/********************************************************************************
** Form generated from reading UI file 'forgetcompanyname.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORGETCOMPANYNAME_H
#define UI_FORGETCOMPANYNAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_forgetcompanyname
{
public:
    QWidget *widget;
    QWidget *widget_2;
    QPushButton *pb_cancel;
    QLineEdit *le_name;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *le_email;
    QPushButton *pb_ok;
    QLabel *label;
    QLabel *register_company_message;

    void setupUi(QWidget *forgetcompanyname)
    {
        if (forgetcompanyname->objectName().isEmpty())
            forgetcompanyname->setObjectName(QStringLiteral("forgetcompanyname"));
        forgetcompanyname->resize(894, 524);
        forgetcompanyname->setAutoFillBackground(true);
        forgetcompanyname->setStyleSheet(QLatin1String("\n"
"color:#fff"));
        widget = new QWidget(forgetcompanyname);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 891, 521));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setAutoFillBackground(false);
        widget->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/Image/background.jpg);"));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(230, 90, 471, 271));
        widget_2->setStyleSheet(QLatin1String("border-image:none;\n"
"border-radius:16px;\n"
"background:rgba(0,0,0,0.3);\n"
"color:#fff"));
        pb_cancel = new QPushButton(widget_2);
        pb_cancel->setObjectName(QStringLiteral("pb_cancel"));
        pb_cancel->setGeometry(QRect(290, 210, 75, 23));
        pb_cancel->setStyleSheet(QLatin1String("background: rgba(154, 207, 206,0.5);\n"
"color: rgb(255, 255, 255);\n"
"border:none;\n"
"border-radius:7px;\n"
"cursor:pointer;\n"
"border-image:none;\n"
""));
        le_name = new QLineEdit(widget_2);
        le_name->setObjectName(QStringLiteral("le_name"));
        le_name->setGeometry(QRect(170, 130, 201, 31));
        le_name->setStyleSheet(QLatin1String("border-radius: 10px;\n"
"border: 1px solid #4288CE;\n"
"border-image:none;\n"
"color:#fff;\n"
""));
        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(93, 80, 71, 21));
        label_2->setStyleSheet(QLatin1String("border-image:none;\n"
"background:rgba(255,255,255,0);"));
        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(93, 129, 71, 21));
        label_3->setStyleSheet(QLatin1String("border-image:none;\n"
"background:rgba(255,255,255,0);"));
        le_email = new QLineEdit(widget_2);
        le_email->setObjectName(QStringLiteral("le_email"));
        le_email->setGeometry(QRect(170, 80, 201, 31));
        le_email->setStyleSheet(QLatin1String("border-radius: 10px;\n"
"border: 1px solid #4288CE;\n"
"border-image:none;\n"
"color:#fff;\n"
""));
        pb_ok = new QPushButton(widget_2);
        pb_ok->setObjectName(QStringLiteral("pb_ok"));
        pb_ok->setGeometry(QRect(120, 210, 75, 23));
        pb_ok->setStyleSheet(QLatin1String("background: rgba(154, 207, 206,0.5);\n"
"color: rgb(255, 255, 255);\n"
"border:none;\n"
"border-radius:7px;\n"
"cursor:pointer;\n"
"border-image:none;\n"
""));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 30, 871, 41));
        label->setStyleSheet(QLatin1String("font-size:24px;\n"
"border-image:none;\n"
"font-weight:600;"));
        label->setAlignment(Qt::AlignCenter);
        register_company_message = new QLabel(widget);
        register_company_message->setObjectName(QStringLiteral("register_company_message"));
        register_company_message->setGeometry(QRect(340, 450, 221, 20));
        register_company_message->setStyleSheet(QLatin1String("color: rgb(170, 170, 127);\n"
"border-image:none;"));

        retranslateUi(forgetcompanyname);

        QMetaObject::connectSlotsByName(forgetcompanyname);
    } // setupUi

    void retranslateUi(QWidget *forgetcompanyname)
    {
        forgetcompanyname->setWindowTitle(QApplication::translate("forgetcompanyname", "Form", 0));
        pb_cancel->setText(QApplication::translate("forgetcompanyname", "\345\217\226\346\266\210", 0));
        label_2->setText(QApplication::translate("forgetcompanyname", "\351\202\256\347\256\261", 0));
        label_3->setText(QApplication::translate("forgetcompanyname", "\345\247\223\345\220\215", 0));
        pb_ok->setText(QApplication::translate("forgetcompanyname", "\347\241\256\350\256\244", 0));
        label->setText(QApplication::translate("forgetcompanyname", "\345\205\254\345\217\270\345\220\215\347\247\260", 0));
        register_company_message->setText(QApplication::translate("forgetcompanyname", "2682178536@qq.com\345\256\242\346\210\267QQ\357\274\2322682178536", 0));
    } // retranslateUi

};

namespace Ui {
    class forgetcompanyname: public Ui_forgetcompanyname {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORGETCOMPANYNAME_H
