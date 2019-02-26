/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

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

class Ui_Register
{
public:
    QWidget *widget_2;
    QWidget *widget;
    QLabel *label;
    QLineEdit *register_company_name;
    QLineEdit *company_queren_pwd;
    QLineEdit *company_email;
    QLabel *label_5;
    QLabel *label_4;
    QLabel *label_2;
    QLineEdit *company_pwd;
    QLineEdit *company_xingming;
    QLabel *label_3;
    QPushButton *pb_zhuce;
    QPushButton *pb_quxiao;
    QLineEdit *company_queren_email;
    QLabel *label_7;
    QPushButton *pb_isVersion;
    QPushButton *pb_isVersion_queren;
    QLabel *label_6;
    QLabel *register_company_message;

    void setupUi(QWidget *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName(QStringLiteral("Register"));
        Register->resize(894, 524);
        widget_2 = new QWidget(Register);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(-10, 0, 901, 521));
        widget_2->setStyleSheet(QLatin1String("border-image: url(:/new/prefix1/Image/background.jpg);\n"
"color:#fff;"));
        widget = new QWidget(widget_2);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(160, 90, 561, 341));
        widget->setStyleSheet(QLatin1String("border-image:none;\n"
"border-radius:16px;\n"
"background:rgba(0,0,0,0.3);\n"
"color:#fff"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 30, 51, 21));
        label->setStyleSheet(QLatin1String("border-image:none;\n"
"background-image:none;\n"
"image:none;\n"
"background:rgba(255,255,255,0);"));
        register_company_name = new QLineEdit(widget);
        register_company_name->setObjectName(QStringLiteral("register_company_name"));
        register_company_name->setGeometry(QRect(230, 30, 171, 20));
        register_company_name->setStyleSheet(QLatin1String("border-radius: 10px;\n"
"border: 1px solid #4288CE;\n"
"border-image:none;\n"
"color:#fff;"));
        company_queren_pwd = new QLineEdit(widget);
        company_queren_pwd->setObjectName(QStringLiteral("company_queren_pwd"));
        company_queren_pwd->setGeometry(QRect(230, 230, 171, 20));
        company_queren_pwd->setStyleSheet(QLatin1String("border-radius: 10px;\n"
"border: 1px solid #4288CE;\n"
"border-image:none;\n"
"color:#fff;"));
        company_email = new QLineEdit(widget);
        company_email->setObjectName(QStringLiteral("company_email"));
        company_email->setGeometry(QRect(230, 70, 171, 20));
        company_email->setStyleSheet(QLatin1String("border-radius: 10px;\n"
"border: 1px solid #4288CE;\n"
"border-image:none;\n"
"color:#fff;"));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(150, 230, 54, 21));
        label_5->setStyleSheet(QStringLiteral("background:rgba(255,255,255,0);"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(170, 190, 31, 21));
        label_4->setStyleSheet(QStringLiteral("background:rgba(255,255,255,0);"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(170, 70, 31, 20));
        label_2->setStyleSheet(QStringLiteral("background:rgba(255,255,255,0);"));
        company_pwd = new QLineEdit(widget);
        company_pwd->setObjectName(QStringLiteral("company_pwd"));
        company_pwd->setGeometry(QRect(230, 190, 171, 20));
        company_pwd->setStyleSheet(QLatin1String("border-radius: 10px;\n"
"border: 1px solid #4288CE;\n"
"border-image:none;\n"
"color:#fff;"));
        company_xingming = new QLineEdit(widget);
        company_xingming->setObjectName(QStringLiteral("company_xingming"));
        company_xingming->setGeometry(QRect(230, 150, 171, 20));
        company_xingming->setStyleSheet(QLatin1String("border-radius: 10px;\n"
"border: 1px solid #4288CE;\n"
"border-image:none;\n"
"color:#fff;"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(170, 150, 31, 21));
        label_3->setStyleSheet(QStringLiteral("background:rgba(255,255,255,0);"));
        pb_zhuce = new QPushButton(widget);
        pb_zhuce->setObjectName(QStringLiteral("pb_zhuce"));
        pb_zhuce->setGeometry(QRect(170, 290, 75, 23));
        pb_zhuce->setStyleSheet(QLatin1String("background: rgba(154, 207, 206,0.5);\n"
"color: rgb(255, 255, 255);\n"
"border:none;\n"
"border-radius:7px;\n"
"cursor:pointer;\n"
"border-image:none;\n"
"\n"
""));
        pb_quxiao = new QPushButton(widget);
        pb_quxiao->setObjectName(QStringLiteral("pb_quxiao"));
        pb_quxiao->setGeometry(QRect(330, 290, 75, 23));
        pb_quxiao->setStyleSheet(QLatin1String("background: rgba(154, 207, 206,0.5);\n"
"color: rgb(255, 255, 255);\n"
"border:none;\n"
"border-radius:7px;\n"
"cursor:pointer;\n"
"border-image:none;\n"
""));
        company_queren_email = new QLineEdit(widget);
        company_queren_email->setObjectName(QStringLiteral("company_queren_email"));
        company_queren_email->setGeometry(QRect(230, 110, 171, 20));
        company_queren_email->setStyleSheet(QLatin1String("border-radius: 10px;\n"
"border: 1px solid #4288CE;\n"
"border-image:none;\n"
"color:#fff;"));
        label_7 = new QLabel(widget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(150, 110, 54, 20));
        label_7->setStyleSheet(QStringLiteral("background:rgba(255,255,255,0);"));
        pb_isVersion = new QPushButton(widget);
        pb_isVersion->setObjectName(QStringLiteral("pb_isVersion"));
        pb_isVersion->setGeometry(QRect(420, 190, 41, 23));
        pb_isVersion_queren = new QPushButton(widget);
        pb_isVersion_queren->setObjectName(QStringLiteral("pb_isVersion_queren"));
        pb_isVersion_queren->setGeometry(QRect(420, 230, 41, 23));
        label_6 = new QLabel(widget_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(0, 40, 891, 31));
        label_6->setStyleSheet(QLatin1String("font-size:24px;\n"
"border-image:none;\n"
"font-weight:600;"));
        label_6->setAlignment(Qt::AlignCenter);
        register_company_message = new QLabel(widget_2);
        register_company_message->setObjectName(QStringLiteral("register_company_message"));
        register_company_message->setGeometry(QRect(370, 480, 221, 20));
        register_company_message->setStyleSheet(QLatin1String("color: rgb(170, 170, 127);\n"
"border-image:none;"));

        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QWidget *Register)
    {
        Register->setWindowTitle(QApplication::translate("Register", "Form", 0));
        label->setText(QApplication::translate("Register", "\345\205\254\345\217\270\345\220\215\347\247\260", 0));
        label_5->setText(QApplication::translate("Register", "\347\241\256\350\256\244\345\257\206\347\240\201", 0));
        label_4->setText(QApplication::translate("Register", "\345\257\206\347\240\201", 0));
        label_2->setText(QApplication::translate("Register", "\351\202\256\347\256\261", 0));
        label_3->setText(QApplication::translate("Register", "\345\247\223\345\220\215", 0));
        pb_zhuce->setText(QApplication::translate("Register", "\346\263\250\345\206\214", 0));
        pb_quxiao->setText(QApplication::translate("Register", "\345\217\226\346\266\210", 0));
        company_queren_email->setText(QString());
        label_7->setText(QApplication::translate("Register", "\347\241\256\350\256\244\351\202\256\347\256\261", 0));
        pb_isVersion->setText(QApplication::translate("Register", "\347\234\274\347\235\233", 0));
        pb_isVersion_queren->setText(QApplication::translate("Register", "\347\234\274\347\235\233", 0));
        label_6->setText(QApplication::translate("Register", "\346\263\250\345\206\214\346\226\260\345\205\254\345\217\270\350\264\246\346\210\267", 0));
        register_company_message->setText(QApplication::translate("Register", "2682178536@qq.com\345\256\242\346\210\267QQ\357\274\2322682178536", 0));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
