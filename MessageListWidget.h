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

#ifndef MESSAGELISTWIDGET_H
#define MESSAGELISTWIDGET_H

#include <QListWidget>
#include <QList>
#include <QVBoxLayout>
#include <QStyleOption>
#include <QPainter>
#include <QScrollArea>
#include <MessageWidget.h>

class MessageListWidget : public QWidget
{
    Q_OBJECT
private:
    QList<MessageWidget*> *widgetList;
    QVBoxLayout* layout;
    QScrollBar* scrollBar;

public:
    explicit MessageListWidget(QWidget *parent = 0);
    void setupUi();

    void add(MessageWidget* widget);

    int count();
    void removeAt(int i);
    void clear();
    MessageWidget* elementAt(int i);
    //void paintEvent(QPaintEvent *);

signals:
    
public slots:
    void add(xPLMessage message);

};

#endif // MESSAGELISTWIDGET_H
