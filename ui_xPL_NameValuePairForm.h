/********************************************************************************
** Form generated from reading UI file 'xPL_NameValuePairForm.ui'
**
** Created: Mon Aug 26 16:46:32 2013
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XPL_NAMEVALUEPAIRFORM_H
#define UI_XPL_NAMEVALUEPAIRFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_xPL_NameValuePairForm
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *namePartWidget;
    QGridLayout *namePartLayout;
    QLabel *label;
    QWidget *valuePartWidget;
    QGridLayout *valuePartLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *removeToolButton;
    QToolButton *addToolButton;

    void setupUi(QWidget *xPL_NameValuePairForm)
    {
        if (xPL_NameValuePairForm->objectName().isEmpty())
            xPL_NameValuePairForm->setObjectName(QString::fromUtf8("xPL_NameValuePairForm"));
        xPL_NameValuePairForm->resize(433, 40);
        horizontalLayout = new QHBoxLayout(xPL_NameValuePairForm);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        namePartWidget = new QWidget(xPL_NameValuePairForm);
        namePartWidget->setObjectName(QString::fromUtf8("namePartWidget"));
        namePartLayout = new QGridLayout(namePartWidget);
        namePartLayout->setObjectName(QString::fromUtf8("namePartLayout"));

        horizontalLayout->addWidget(namePartWidget);

        label = new QLabel(xPL_NameValuePairForm);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label);

        valuePartWidget = new QWidget(xPL_NameValuePairForm);
        valuePartWidget->setObjectName(QString::fromUtf8("valuePartWidget"));
        valuePartLayout = new QGridLayout(valuePartWidget);
        valuePartLayout->setObjectName(QString::fromUtf8("valuePartLayout"));

        horizontalLayout->addWidget(valuePartWidget);

        widget = new QWidget(xPL_NameValuePairForm);
        widget->setObjectName(QString::fromUtf8("widget"));
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        removeToolButton = new QToolButton(widget);
        removeToolButton->setObjectName(QString::fromUtf8("removeToolButton"));

        horizontalLayout_2->addWidget(removeToolButton);

        addToolButton = new QToolButton(widget);
        addToolButton->setObjectName(QString::fromUtf8("addToolButton"));

        horizontalLayout_2->addWidget(addToolButton);


        horizontalLayout->addWidget(widget);


        retranslateUi(xPL_NameValuePairForm);

        QMetaObject::connectSlotsByName(xPL_NameValuePairForm);
    } // setupUi

    void retranslateUi(QWidget *xPL_NameValuePairForm)
    {
        xPL_NameValuePairForm->setWindowTitle(QApplication::translate("xPL_NameValuePairForm", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("xPL_NameValuePairForm", "=", 0, QApplication::UnicodeUTF8));
        removeToolButton->setText(QApplication::translate("xPL_NameValuePairForm", "...", 0, QApplication::UnicodeUTF8));
        addToolButton->setText(QApplication::translate("xPL_NameValuePairForm", "...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class xPL_NameValuePairForm: public Ui_xPL_NameValuePairForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XPL_NAMEVALUEPAIRFORM_H
