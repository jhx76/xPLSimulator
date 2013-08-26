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

#include "MessageWidget.h"

MessageWidget::MessageWidget(const xPLMessage& message, QWidget *view) : QWidget(view)
{
    this->message = message;
    this->expanded = false;
    this->mouseClick = false;
    this->lblEntireMessage = NULL;
    this->lblSchema = NULL;
    this->lblType = NULL;
    this->lblSource = NULL;
    this->lblTarget = NULL;
    this->lblTime = NULL;
    this->layout = NULL;
    this->lblMsgTile = NULL;
    this->expandButton = NULL;
    this->setupUi();
    connect(this->expandButton, SIGNAL(clicked()), this, SLOT(onWidgetClicked()));
}

void MessageWidget::setupUi() {

    this->layout = new QGridLayout();
    lblTime = new QLabel(QDateTime::currentDateTime().toString("dd.MM.yyyy (hh:mm:ss)"), this);
    layout->addWidget(lblTime, 0,0,1,1);
    this->expandButton = new QToolButton(this);
    expandButton->setToolTip("Details...");
    layout->addWidget(expandButton, 0, 1, 1, 1, Qt::AlignRight);


    QString strType = "<b>$";
    switch (message.getMessageType()) {
    case xPLMessage::COMMAND:
        strType += "COMMAND</b>";
        this->setStyleSheet("background: red;");
        break;
    case xPLMessage::TRIGGER:
        strType += "TRIGGER</b>";
        setStyleSheet("background: blue;");
        break;
    case xPLMessage::STATUS:
        strType += "STATUS</b>";
        setStyleSheet("background: yellow;");
        break;
    default:
        strType += "UNKNOWN";
        break;
    }
    lblType = new QLabel(strType, this);
    layout->addWidget(lblType, 1, 0);
    lblSchema = new QLabel("<b>Schema</b> : "+message.getMessageSchema()+"."+message.getMessageClass(), this);
    layout->addWidget(lblSchema, 2, 0);
    lblSource = new QLabel("<b>Source</b> : "+message.getSourceAddress(), this);
    layout->addWidget(lblSource, 1, 1);
    lblTarget = new QLabel("<b>Target</b> : "+message.getTargetAddress(), this);
    layout->addWidget(lblTarget, 2, 1);
    setLayout(layout);
}

void MessageWidget::paintEvent(QPaintEvent *) {
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void MessageWidget::onWidgetClicked() {
    if(!expanded) {
        lblMsgTile = new QLabel("<b>Complete message:</b>", this);
        this->layout->addWidget(lblMsgTile, 3, 0, 1, 2);
        this->lblEntireMessage = new QLabel(message.toString(), this);
        this->layout->addWidget(lblEntireMessage, 4, 0, 1, 2);
        expanded = true;
    }
    else {
        this->layout->removeWidget(lblMsgTile);
        delete lblMsgTile;
        this->layout->removeWidget(lblEntireMessage);
        delete lblEntireMessage;
        expanded = false;
    }
}

void MessageWidget::mouseReleaseEvent(QMouseEvent *event) {
    if ((mouseClick) && (event->pos() == lastClickPoint))
    {
        emit mouseClickEvent();
    }
}

void MessageWidget::mousePressEvent(QMouseEvent *event) {
        // store click position
        lastClickPoint = event->pos();
        // set the flag meaning "click begin"
        mouseClick = true;
}
