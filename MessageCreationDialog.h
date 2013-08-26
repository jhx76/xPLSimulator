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

#ifndef MESSAGECREATIONDIALOG_H
#define MESSAGECREATIONDIALOG_H

#include <QDialog>
#include <QList>
#include <QString>
#include <QXmlQuery>
#include <QFile>
#include <xPL_NameValuePairForm.h>

namespace Ui {
class MessageCreationDialog;
}

class MessageCreationDialog : public QDialog
{
    Q_OBJECT
private:
    Ui::MessageCreationDialog *ui;
    QList<xPL_NameValuePairForm*>* nvPairList;
    QString templateFilePath;



public:
    explicit MessageCreationDialog(const QString& templateFilePath, QWidget *parent = 0);
    ~MessageCreationDialog();
    void initializeXml(const QString& templateFilePath);

    //void onComboMessageTypeValueChanged();

};

#endif // MESSAGECREATIONDIALOG_H
