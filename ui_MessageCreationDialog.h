/********************************************************************************
** Form generated from reading UI file 'MessageCreationDialog.ui'
**
** Created: Mon Aug 26 16:46:32 2013
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGECREATIONDIALOG_H
#define UI_MESSAGECREATIONDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MessageCreationDialog
{
public:
    QGridLayout *gridLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboMessageType;
    QLabel *label_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QSpinBox *hopSpinBox;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *sourceEdit;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLineEdit *targetEdit;
    QLabel *label_6;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_5;
    QComboBox *comboSchema;
    QLabel *label_7;
    QComboBox *comboClass;
    QLabel *label_8;
    QWidget *bodyWidget;
    QVBoxLayout *bodyLayout;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *MessageCreationDialog)
    {
        if (MessageCreationDialog->objectName().isEmpty())
            MessageCreationDialog->setObjectName(QString::fromUtf8("MessageCreationDialog"));
        MessageCreationDialog->resize(304, 335);
        gridLayout = new QGridLayout(MessageCreationDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        frame = new QFrame(MessageCreationDialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 0, -1, 0);
        widget = new QWidget(frame);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label);

        comboMessageType = new QComboBox(widget);
        comboMessageType->setObjectName(QString::fromUtf8("comboMessageType"));
        comboMessageType->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout->addWidget(comboMessageType);


        verticalLayout->addWidget(widget);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(label_2);

        widget_2 = new QWidget(frame);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(label_3);

        hopSpinBox = new QSpinBox(widget_2);
        hopSpinBox->setObjectName(QString::fromUtf8("hopSpinBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(hopSpinBox->sizePolicy().hasHeightForWidth());
        hopSpinBox->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(hopSpinBox);


        verticalLayout->addWidget(widget_2);

        widget_3 = new QWidget(frame);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(widget_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(label_4);

        sourceEdit = new QLineEdit(widget_3);
        sourceEdit->setObjectName(QString::fromUtf8("sourceEdit"));

        horizontalLayout_3->addWidget(sourceEdit);


        verticalLayout->addWidget(widget_3);

        widget_4 = new QWidget(frame);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_4 = new QHBoxLayout(widget_4);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(widget_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(label_5);

        targetEdit = new QLineEdit(widget_4);
        targetEdit->setObjectName(QString::fromUtf8("targetEdit"));

        horizontalLayout_4->addWidget(targetEdit);


        verticalLayout->addWidget(widget_4);

        label_6 = new QLabel(frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(label_6);

        widget_5 = new QWidget(frame);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_5 = new QHBoxLayout(widget_5);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        comboSchema = new QComboBox(widget_5);
        comboSchema->setObjectName(QString::fromUtf8("comboSchema"));

        horizontalLayout_5->addWidget(comboSchema);

        label_7 = new QLabel(widget_5);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(label_7);

        comboClass = new QComboBox(widget_5);
        comboClass->setObjectName(QString::fromUtf8("comboClass"));

        horizontalLayout_5->addWidget(comboClass);


        verticalLayout->addWidget(widget_5);

        label_8 = new QLabel(frame);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        sizePolicy.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(label_8);

        bodyWidget = new QWidget(frame);
        bodyWidget->setObjectName(QString::fromUtf8("bodyWidget"));
        bodyLayout = new QVBoxLayout(bodyWidget);
        bodyLayout->setObjectName(QString::fromUtf8("bodyLayout"));

        verticalLayout->addWidget(bodyWidget);


        gridLayout->addWidget(frame, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(MessageCreationDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(MessageCreationDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), MessageCreationDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), MessageCreationDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(MessageCreationDialog);
    } // setupUi

    void retranslateUi(QDialog *MessageCreationDialog)
    {
        MessageCreationDialog->setWindowTitle(QApplication::translate("MessageCreationDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MessageCreationDialog", "xpl-", 0, QApplication::UnicodeUTF8));
        comboMessageType->clear();
        comboMessageType->insertItems(0, QStringList()
         << QApplication::translate("MessageCreationDialog", "stat", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MessageCreationDialog", "trig", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MessageCreationDialog", "cmnd", 0, QApplication::UnicodeUTF8)
        );
        label_2->setText(QApplication::translate("MessageCreationDialog", "{", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MessageCreationDialog", "hop=", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MessageCreationDialog", "source=", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MessageCreationDialog", "target=", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MessageCreationDialog", "}", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MessageCreationDialog", ".", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MessageCreationDialog", "{", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MessageCreationDialog: public Ui_MessageCreationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGECREATIONDIALOG_H
