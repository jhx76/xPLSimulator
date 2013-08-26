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

#include "MessageListWidget.h"

MessageListWidget::MessageListWidget(QWidget *parent) : QWidget(parent) {
    this->widgetList = new QList<MessageWidget*>();
    layout = NULL;
    setupUi();
}

void MessageListWidget::setupUi() {
    layout = new QVBoxLayout(this);
    layout->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    this->setLayout(layout);
}

void MessageListWidget::add(xPLMessage message) {
    MessageWidget* widget = new MessageWidget(message, this);
    this->add(widget);
}

/*
void MessageListWidget::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
*/

void MessageListWidget::add(MessageWidget *widget) {
    widget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    this->widgetList->append(widget);
    this->layout->addWidget(widget);
}


void MessageListWidget::clear() {
    while(!this->widgetList->isEmpty()) {
        MessageWidget* tmpWidget = widgetList->takeFirst();
       // this->layout->removeWidget(tmpWidget);
        delete tmpWidget;
    }
}
