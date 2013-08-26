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

#include "xPL_NameValuePairForm.h"
#include "ui_xPL_NameValuePairForm.h"

xPL_NameValuePairForm::xPL_NameValuePairForm(NVPairType type, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::xPL_NameValuePairForm)
{
    ui->setupUi(this);
    this->type = type;
    QComboBox* nameComboBox = NULL;
    QLineEdit* nameLineEdit =  NULL;
    QComboBox* valueComboBox = NULL;
    QSpinBox* valueSpinBox = NULL;
    QLineEdit* valueLineEdit = NULL;
    switch(type) {
        case COMBOLISTBOX:
            nameComboBox = new QComboBox(this);
            ui->namePartLayout->addWidget(nameComboBox);
            connect(nameComboBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(onNamePartChanged(QString)));
            this->nameWidgetPtr = nameComboBox;
            valueComboBox = new QComboBox(this);
            ui->valuePartLayout->addWidget(valueComboBox);
            connect(valueComboBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(onValuePartChanged(QString)));
            this->valueWidgetPtr = valueComboBox;
            break;

        case NUMERIC:
            nameComboBox = new QComboBox(this);
            ui->namePartLayout->addWidget(nameComboBox);
            connect(nameComboBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(onNamePartChanged(QString)));
            this->nameWidgetPtr = nameComboBox;
            valueSpinBox = new QSpinBox(this);
            ui->valuePartLayout->addWidget(valueSpinBox);
            connect(valueSpinBox, SIGNAL(valueChanged(QString)), this, SLOT(onValuePartChanged(QString)));
            this->valueWidgetPtr = valueSpinBox;
            break;

        case TEXT:
            nameComboBox = new QComboBox(this);
            ui->namePartLayout->addWidget(nameComboBox);
            connect(nameComboBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(onNamePartChanged(QString)));
            this->nameWidgetPtr = nameComboBox;
            valueLineEdit = new QLineEdit(this);
            ui->valuePartLayout->addWidget(valueLineEdit);
            connect(valueLineEdit, SIGNAL(textChanged(QString)), this, SLOT(onValuePartChanged(QString)));
            this->valueWidgetPtr = valueLineEdit;
            break;

        default:
            nameLineEdit = new QLineEdit(this);
            ui->namePartLayout->addWidget(nameLineEdit);
            connect(nameLineEdit, SIGNAL(textChanged(QString)), this, SLOT(onNamePartChanged(QString)));
            this->nameWidgetPtr = nameLineEdit;
            valueLineEdit = new QLineEdit(this);
            ui->valuePartLayout->addWidget(valueLineEdit);
            connect(valueLineEdit, SIGNAL(textChanged(QString)), this, SLOT(onValuePartChanged(QString)));
            this->valueWidgetPtr = valueLineEdit;
            break;
    };
    connect(ui->addToolButton, SIGNAL(clicked()), this, SLOT(onAddToolButtonClick()));
    connect(ui->removeToolButton, SIGNAL(clicked()), this, SLOT(onRemoveToolButtonClick()));
}

xPL_NameValuePairForm::~xPL_NameValuePairForm() {
    delete ui;
}

void xPL_NameValuePairForm::onAddToolButtonClick() {

}

void xPL_NameValuePairForm::onRemoveToolButtonClick() {

}

void xPL_NameValuePairForm::onNamePartChanged(QString value) {
    this->nameValuePair.setName(value);
    qDebug()<<"nameValuePair changed : "<<nameValuePair.getName()<<"="<<nameValuePair.getValue();
}

void xPL_NameValuePairForm::onValuePartChanged(QString value) {
    this->nameValuePair.setValue(value);
    qDebug()<<"nameValuePair changed : "<<nameValuePair.getName()<<"="<<nameValuePair.getValue();
}

void xPL_NameValuePairForm::forceGraphicNamePart(QString/* value*/) {

}

void xPL_NameValuePairForm::forceGraphicValuePart(QString/* value*/) {

}
