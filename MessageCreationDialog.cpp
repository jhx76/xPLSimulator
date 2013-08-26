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

#include "MessageCreationDialog.h"
#include "ui_MessageCreationDialog.h"

MessageCreationDialog::MessageCreationDialog(const QString& templateFilePath, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MessageCreationDialog)
{
    ui->setupUi(this);
    nvPairList = new QList<xPL_NameValuePairForm*>();
    this->templateFilePath = templateFilePath;

    initializeXml(templateFilePath);
}

MessageCreationDialog::~MessageCreationDialog()
{
    delete ui;
}

void MessageCreationDialog::initializeXml(const QString& /*templateFilePath*/) {

}
