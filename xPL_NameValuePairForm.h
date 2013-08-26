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

#ifndef XPL_NAMEVALUEPAIRFORM_H
#define XPL_NAMEVALUEPAIRFORM_H

#include <QWidget>
#include <QComboBox>
#include <QLineEdit>
#include <QSpinBox>
#include <QDebug>
#include <xPLNameValuePair.h>

namespace Ui {
class xPL_NameValuePairForm;
}

class xPL_NameValuePairForm : public QWidget
{
    Q_OBJECT
public:
    typedef enum  {
        COMBOLISTBOX,
        NUMERIC,
        TEXT
    } NVPairType;

private:
    Ui::xPL_NameValuePairForm *ui;
    NVPairType type;
    xPLNameValuePair nameValuePair;
    QWidget* nameWidgetPtr;
    QWidget* valueWidgetPtr;

public:
    explicit xPL_NameValuePairForm(NVPairType type, QWidget *parent = 0);
    ~xPL_NameValuePairForm();

public slots:
    void onAddToolButtonClick();
    void onRemoveToolButtonClick();
    void onNamePartChanged(QString value);
    void onValuePartChanged(QString value);
    void forceGraphicValuePart(QString value);
    void forceGraphicNamePart(QString value);
};

#endif // XPL_NAMEVALUEPAIRFORM_H
