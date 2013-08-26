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

#include "SendMessageDialog.h"
#include "ui_SendMessageDialog.h"

SendMessageDialog::SendMessageDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SendMessageDialog)
{
    ui->setupUi(this);
    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(onAccept()));
}

SendMessageDialog::~SendMessageDialog()
{
    delete ui;
}

void SendMessageDialog::onAccept() {
    try {
        xPLMessage message(ui->messageEdit->toPlainText());
        emit this->messageCreated(message);
        this->accept();
    }
    catch(const QString& exception) {
        qDebug() << exception;
        qDebug() << "please remove issues !";
    }
}
