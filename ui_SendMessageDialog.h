/********************************************************************************
** Form generated from reading UI file 'SendMessageDialog.ui'
**
** Created: Mon Aug 26 16:46:32 2013
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENDMESSAGEDIALOG_H
#define UI_SENDMESSAGEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPlainTextEdit>

QT_BEGIN_NAMESPACE

class Ui_SendMessageDialog
{
public:
    QGridLayout *gridLayout;
    QPlainTextEdit *messageEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SendMessageDialog)
    {
        if (SendMessageDialog->objectName().isEmpty())
            SendMessageDialog->setObjectName(QString::fromUtf8("SendMessageDialog"));
        SendMessageDialog->resize(400, 300);
        gridLayout = new QGridLayout(SendMessageDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        messageEdit = new QPlainTextEdit(SendMessageDialog);
        messageEdit->setObjectName(QString::fromUtf8("messageEdit"));

        gridLayout->addWidget(messageEdit, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(SendMessageDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(SendMessageDialog);
        QObject::connect(buttonBox, SIGNAL(rejected()), SendMessageDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SendMessageDialog);
    } // setupUi

    void retranslateUi(QDialog *SendMessageDialog)
    {
        SendMessageDialog->setWindowTitle(QApplication::translate("SendMessageDialog", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SendMessageDialog: public Ui_SendMessageDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENDMESSAGEDIALOG_H
