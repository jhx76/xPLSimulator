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

#ifndef SENDMESSAGEDIALOG_H
#define SENDMESSAGEDIALOG_H

#include <QDialog>
#include <xPLMessage.h>

namespace Ui {
class SendMessageDialog;
}

class SendMessageDialog : public QDialog
{
    Q_OBJECT
private:
    Ui::SendMessageDialog *ui;

private slots:
    void onAccept();

public:
    explicit SendMessageDialog(QWidget *parent = 0);
    ~SendMessageDialog();

signals:
    void messageCreated(xPLMessage);


};

#endif // SENDMESSAGEDIALOG_H
