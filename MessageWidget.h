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

#ifndef MESSAGEWIDGET_H
#define MESSAGEWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QColor>
#include <QGridLayout>
#include <QStyleOption>
#include <QPainter>
#include <QMouseEvent>
#include <QDateTime>
#include <QToolButton>
#include <xPLMessage.h>


class MessageWidget : public QWidget
{
    Q_OBJECT
private:
    xPLMessage message;
    QGridLayout* layout;
    QLabel* lblMsgTile;
    QLabel* lblTime;
    QLabel* lblType;
    QLabel* lblSchema;
    QLabel* lblSource;
    QLabel* lblTarget;
    QLabel* lblEntireMessage;
    QToolButton* expandButton;
    bool expanded;

    // member variable to store click position
    QPoint lastClickPoint;
    // member variable - flag of click beginning
    bool mouseClick;

    virtual void mouseReleaseEvent(QMouseEvent* event);
    virtual void mousePressEvent(QMouseEvent* event);

public:
    explicit MessageWidget(const xPLMessage& message, QWidget *parent = 0);
    void setupUi();
    void paintEvent(QPaintEvent *);

signals:
    void mouseClickEvent();

public slots:
    void onWidgetClicked();
};

#endif // MESSAGEWIDGET_H
