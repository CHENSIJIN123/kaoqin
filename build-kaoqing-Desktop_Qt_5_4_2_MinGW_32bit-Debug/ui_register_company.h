/********************************************************************************
** Form generated from reading UI file 'register_company.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_COMPANY_H
#define UI_REGISTER_COMPANY_H

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

class Ui_register_company
{
public:
    QWidget *widget_2;
    QWidget *widget;
    QPushButton *register_login;
    QLineEdit *register_company_name;
    QPushButton *register_new_company;
    QPushButton *register_forget_company_name;
    QPushButton *register_choose_login_way;
    QLabel *register_company_message;

    void setupUi(QWidget *register_company)
    {
        if (register_company->objectName().isEmpty())
            register_company->setObjectName(QStringLiteral("register_company"));
        register_company->resize(894, 524);
        register_company->setStyleSheet(QStringLiteral("border:none;"));
        widget_2 = new QWidget(register_company);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(-10, 0, 901, 521));
        widget_2->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/Image/background.jpg);"));
        widget = new QWidget(widget_2);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(230, 90, 471, 271));
        widget->setStyleSheet(QLatin1String("border-image:none;\n"
"border-radius:16px;\n"
"background:rgba(0,0,0,0.3);\n"
"color:#fff"));
        register_login = new QPushButton(widget);
        register_login->setObjectName(QStringLiteral("register_login"));
        register_login->setGeometry(QRect(310, 70, 81, 41));
        register_login->setStyleSheet(QLatin1String("display: inline-block;\n"
" padding: 6px 12px;\n"
"		    margin-bottom: 0;\n"
"		    font-size: 14px;\n"
"		    font-weight: 400;\n"
"		    line-height: 1.42857143;\n"
"		    text-align: center;\n"
"		    white-space: nowrap;\n"
"		    vertical-align: middle;\n"
"		    -ms-touch-action: manipulation;\n"
"		    touch-action: manipulation;\n"
"		    cursor: pointer;\n"
"		    user-select: none;\n"
"		    background-image: none;\n"
"		    border: 1px solid transparent;\n"
"		    border-radius: 4px;\n"
"			color: #fff;\n"
"		    background-color: #31b0d5;\n"
"		    border-color: #269abc;\n"
"border-image:none;\n"
""));
        register_company_name = new QLineEdit(widget);
        register_company_name->setObjectName(QStringLiteral("register_company_name"));
        register_company_name->setGeometry(QRect(70, 70, 251, 41));
        register_company_name->setStyleSheet(QLatin1String("border-radius: 10px;\n"
"border: 1px solid #4288CE;\n"
"border-image:none;\n"
"color:#fff;\n"
""));
        register_new_company = new QPushButton(widget);
        register_new_company->setObjectName(QStringLiteral("register_new_company"));
        register_new_company->setGeometry(QRect(290, 200, 121, 31));
        register_new_company->setStyleSheet(QLatin1String("border-image:none;\n"
"border:1px solid rgba(0,0,0,0);\n"
"border-radius:4px;\n"
"background:rgba(0,0,0,0.25);\n"
"color: #fff;\n"
"background:rgba(255,255,255,0);\n"
"\n"
""));
        register_new_company->setFlat(false);
        register_forget_company_name = new QPushButton(widget);
        register_forget_company_name->setObjectName(QStringLiteral("register_forget_company_name"));
        register_forget_company_name->setGeometry(QRect(60, 200, 111, 31));
        register_forget_company_name->setStyleSheet(QLatin1String("border-image:none;\n"
"border:1px solid rgba(0,0,0,0);\n"
"border-radius:4px;\n"
"background:rgba(0,0,0,0.25);\n"
"color: #fff;\n"
"background:rgba(255,255,255,0);"));
        register_forget_company_name->setFlat(false);
        register_company_name->raise();
        register_new_company->raise();
        register_forget_company_name->raise();
        register_login->raise();
        register_choose_login_way = new QPushButton(widget_2);
        register_choose_login_way->setObjectName(QStringLiteral("register_choose_login_way"));
        register_choose_login_way->setGeometry(QRect(40, 430, 51, 51));
        register_choose_login_way->setStyleSheet(QLatin1String("border-radius:25px;\n"
"background:#31b0d5;\n"
"color:#fff;\n"
"border-image:none;"));
        register_company_message = new QLabel(widget_2);
        register_company_message->setObjectName(QStringLiteral("register_company_message"));
        register_company_message->setGeometry(QRect(340, 460, 221, 20));
        register_company_message->setStyleSheet(QLatin1String("color: rgb(170, 170, 127);\n"
"border-image:none;"));

        retranslateUi(register_company);

        QMetaObject::connectSlotsByName(register_company);
    } // setupUi

    void retranslateUi(QWidget *register_company)
    {
        register_company->setWindowTitle(QApplication::translate("register_company", "register_company", 0));
        register_login->setText(QApplication::translate("register_company", "\347\231\273\345\275\225", 0));
        register_company_name->setText(QString());
        register_company_name->setPlaceholderText(QApplication::translate("register_company", "\350\257\267\350\276\223\345\205\245\346\202\250\345\205\254\345\217\270\347\232\204\345\220\215\345\255\227", 0));
        register_new_company->setText(QApplication::translate("register_company", "\346\263\250\345\206\214\346\226\260\345\205\254\345\217\270", 0));
        register_forget_company_name->setText(QApplication::translate("register_company", "\345\277\230\350\256\260\345\205\254\345\217\270\345\220\215\347\247\260", 0));
        register_choose_login_way->setText(QApplication::translate("register_company", "\347\225\214\351\235\242", 0));
        register_company_message->setText(QApplication::translate("register_company", "2682178536@qq.com\345\256\242\346\210\267QQ\357\274\2322682178536", 0));
    } // retranslateUi

};

namespace Ui {
    class register_company: public Ui_register_company {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_COMPANY_H
