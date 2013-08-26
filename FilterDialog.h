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

#ifndef FLITERDIALOG_H
#define FLITERDIALOG_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QPlainTextEdit>

class FilterTextEdit : public QPlainTextEdit
{
    Q_OBJECT
private:

public:
    FilterTextEdit(QWidget* parent = 0);

signals:

public slots:

};

class FilterDialog : public QWidget
{
    Q_OBJECT
private:
    QPushButton* okButton;
    QPushButton* cancelButton;
    FilterTextEdit* filterTextEdit;
    QGridLayout* layout;

public:
    FilterDialog(QWidget* parent = 0);
    void setupUi();

signals:

public slots:
    void onOkButtonClick();
    void onCancelButtonClick();


};

#endif // FLITERDIALOG_H
