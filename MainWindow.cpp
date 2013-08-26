/*
    This file is part of xPL_Simulator.

    xPL_Simulator is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    xPL_Simulator is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with xPL_Simulator.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->modelMsgList = new MessageListWidget(this);
    ui->scrollArea->setStyleSheet("background: white;");
    ui->scrollArea->setWidget(modelMsgList);
    this->setStyleSheet(getStyleSheet());
    this->xplPortUsed = -1;
    this->connected = false;
    this->xplSocket = NULL;
    this->hbeatTimer = NULL;
    this->setupToolBar();
    connect(this, SIGNAL(xPLMessageReceived(xPLMessage)), modelMsgList, SLOT(add(xPLMessage)));
    connect(ui->actionQuit, SIGNAL(triggered()), qApp, SLOT(quit()));
    try {
        this->initializeXPLNetwork();
    }
    catch(const QString& exception) {
        qDebug() << exception;
    }


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupMenu() {
    connect(ui->actionQuit, SIGNAL(triggered()), qApp, SLOT(quit()));
}

void MainWindow::setupToolBar() {
    actionClear = new QAction(this);
    actionClear->setIcon(QIcon("../images/icon_clear.png"));
    connect(actionClear, SIGNAL(triggered()), this, SLOT(onActionClearTriggered()));
    ui->mainToolBar->addAction(actionClear);


    actionFilter = new QAction(this);
    actionFilter->setIcon(QIcon("../images/icon_filter.png"));
    connect(actionFilter, SIGNAL(triggered()), this, SLOT(onActionFilterTriggered()));
    ui->mainToolBar->addAction(actionFilter);

    actionSendMessage = new QAction(this);
    actionSendMessage->setIcon(QIcon("../images/icon_send.png"));
    connect(actionSendMessage, SIGNAL(triggered()), this, SLOT(onActionSendMessageTriggered()));
    ui->mainToolBar->addAction(actionSendMessage);
}

void MainWindow::onActionClearTriggered() {
    this->modelMsgList->clear();
}

void MainWindow::onActionFilterTriggered() {
    FilterDialog* filterDialog = new FilterDialog();
    filterDialog->show();
}

void MainWindow::onActionSendMessageTriggered() {
    //MessageCreationDialog* dialog = new MessageCreationDialog();
    SendMessageDialog* dialog = new SendMessageDialog();
    connect(dialog, SIGNAL(messageCreated(xPLMessage)), this, SLOT(sendMessage(xPLMessage)));
    dialog->show();
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

QString MainWindow::getStyleSheet() {
    QString styleSheet = "";
    styleSheet +=
            ".MessageListWidget {"
            "   padding: 10px;"
            "   border-style: solid;"
            "   border-color: black;"
            "   border-width: 1px;"
            "   background: white;"
            "}"
            ".MessageWidget {"
            "   border-style: solid;"
            "   border-color: black;"
            "   border-width: 2px;"
            "}";
    return styleSheet;
}


void MainWindow::initializeXPLNetwork() {
    this->statusBar()->showMessage("Connecting to xPL Network...");
    this->xplSocket = new QUdpSocket(this);
    this->connected = false;
    //Tentative de connection
    for(this->xplPortUsed = MINIMUM_XPL_PORT; !this->connected && this->xplPortUsed <= MAXIMUM_XPL_PORT; this->xplPortUsed++) {
        this->connected = xplSocket->bind(this->xplPortUsed, QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint);
        if(this->connected) {
            //On mappe le event handler
            connect(this->xplSocket, SIGNAL(readyRead()), this, SLOT(readPendingDatagrams()));
            break;
        }
    }
    //On vérifie quand même qu'on est bien connecté !
    if(!this->connected) {
        this->xplPortUsed = -1;
        throw QString("Unable to bind any UDP port between "+ QString::number(MINIMUM_XPL_PORT)+" and "+QString::number(MAXIMUM_XPL_PORT)+" ! connection failed...");
    }
    this->statusBar()->showMessage("Connected.");
    //On est maintenant connecté !
    //Il est temps de récupérer l'IP de la machine !
    QList<QHostAddress> addressList = QNetworkInterface::allAddresses();
    for(int i = 0; i < addressList.count(); i++) {
        qDebug() << addressList.at(i).toString();
        if(addressList.at(i).toString().contains(".") && addressList.at(i).toString() != "127.0.0.1")
            this->hostAddress = addressList.at(i).toString();
    }
    //On envoie le premier heartbeat pour le hub, et on lance le timer !
    this->hbeatTimer = new QTimer(this);
    if(!hbeatTimer)
        throw QString("MEMORY ERROR !");
    int hbeatInterval = 3*60*1000;//en ms
    connect(hbeatTimer, SIGNAL(timeout()), this, SLOT(sendHeartBeatMessage()));
    sendMessage(xPLMessage(
                "xpl-stat\n"
                "{\n"
                "hop=1\n"
                "source=zigbus-xplsimulator.app\n"
                "target=*\n"
                "}\n"
                "hbeat.app\n"
                "{\n"
                "interval="+QString::number(hbeatInterval/60000)+"\n"
                "port="+QString::number(this->xplPortUsed)+"\n"
                "remote-ip="+this->hostAddress+"\n"
                "}\n"));
    //On lance le timer
    hbeatTimer->start(hbeatInterval);
}


void MainWindow::readPendingDatagrams() {
    while (xplSocket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(this->xplSocket->pendingDatagramSize());
        QHostAddress sender;
        quint16 senderPort;
        this->xplSocket->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);
        try {
            xPLMessage messageReceived(datagram);
            emit xPLMessageReceived(messageReceived);
        }
        catch(const QString& exception) {
            qDebug() << exception;
        }
    }
}

void MainWindow::sendMessage(xPLMessage message) {
    QByteArray datagram = message.toString().toLocal8Bit();
    int rslt = this->xplSocket->writeDatagram(datagram.data(), datagram.size(), QHostAddress("192.168.0.255"), BASE_XPL_PORT);
    if(rslt == -1) {
        qDebug() << xplSocket->errorString();
    }
    else
        qDebug() << QString::number(rslt) << " octets envoyes !";
}

void MainWindow::sendHeartBeatMessage() {
    xPLMessage message(
                "xpl-stat\n"
                "{\n"
                "hop=1\n"
                "source=zigbus-xplsimulator.app\n"
                "target=*\n"
                "}\n"
                "hbeat.app\n"
                "{\n"
                "interval="+QString::number(hbeatTimer->interval()*60*1000)+"\n"
                "port="+QString::number(this->xplPortUsed)+"\n"
                "remote-ip="+this->hostAddress+"\n"
                "}\n");
    sendMessage(message);
}

void MainWindow::quitProperly() {

}

