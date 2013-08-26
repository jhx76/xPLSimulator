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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>
#include <QNetworkInterface>
#include <QHostAddress>
#include <QByteArray>
#include <QTimer>
#include <QScrollArea>

#include <MessageListWidget.h>
#include <FilterDialog.h>
#include <SendMessageDialog.h>

#define MINIMUM_XPL_PORT 35352
#define MAXIMUM_XPL_PORT 35420
#define BASE_XPL_PORT 3865

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Ui::MainWindow *ui;
    MessageListWidget* modelMsgList;
    QUdpSocket* xplSocket;
    bool connected;
    int xplPortUsed;
    QString hostAddress;
    QTimer* hbeatTimer;
    QAction* actionFilter;
    QAction* actionClear;
    QAction* actionSendMessage;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setupToolBar();
    void setupMenu();
    QString getStyleSheet();
    void paintEvent(QPaintEvent *);
    void initializeXPLNetwork();

signals:
    void xPLMessageReceived(xPLMessage message);

public slots:
    void quitProperly();
    void readPendingDatagrams();
    void sendMessage(xPLMessage message);

    void onActionClearTriggered();
    void onActionFilterTriggered();
    void onActionSendMessageTriggered();
    void sendHeartBeatMessage();

};

#endif // MAINWINDOW_H
