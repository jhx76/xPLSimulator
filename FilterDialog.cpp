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

#include "FilterDialog.h"

FilterTextEdit::FilterTextEdit(QWidget* parent) : QPlainTextEdit(parent) {

}

FilterDialog::FilterDialog(QWidget *parent) : QWidget(parent) {
    this->okButton = NULL;
    this->cancelButton = NULL;
    this->filterTextEdit = NULL;
    this->setupUi();
}

void FilterDialog::setupUi() {
    layout = new QGridLayout(this);
    filterTextEdit = new FilterTextEdit(this);
    layout->addWidget(filterTextEdit, 0, 0, 1, 3);

    okButton = new QPushButton("Ok", this);
    layout->addWidget(okButton, 1, 1, 1, 1, Qt::AlignLeft);


    cancelButton = new QPushButton("Cancel", this);
    layout->addWidget(cancelButton, 1, 2, 1, 1, Qt::AlignLeft);

    this->setLayout(layout);
}

void FilterDialog::onOkButtonClick() {

}

void FilterDialog::onCancelButtonClick() {
    this->close();
}
