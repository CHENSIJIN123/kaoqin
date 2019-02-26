/********************************************************************************
** Form generated from reading UI file 'userwork.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERWORK_H
#define UI_USERWORK_H

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

class Ui_userwork
{
public:
    QWidget *widget;
    QPushButton *register_choose_login_way;
    QLineEdit *le_name_workNum;
    QLineEdit *le_pwd;
    QPushButton *pb_daka;
    QPushButton *pb_login;
    QLabel *mytime;
    QLabel *register_company_message_2;

    void setupUi(QWidget *userwork)
    {
        if (userwork->objectName().isEmpty())
            userwork->setObjectName(QStringLiteral("userwork"));
        userwork->resize(904, 508);
        userwork->setStyleSheet(QStringLiteral("border:none;"));
        widget = new QWidget(userwork);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(-6, -2, 911, 511));
        widget->setAutoFillBackground(false);
        widget->setStyleSheet(QLatin1String("border-image: url(:/new/prefix1/Image/background.jpg);\n"
"border:none;"));
        register_choose_login_way = new QPushButton(widget);
        register_choose_login_way->setObjectName(QStringLiteral("register_choose_login_way"));
        register_choose_login_way->setGeometry(QRect(10, 430, 51, 51));
        register_choose_login_way->setStyleSheet(QLatin1String("border-radius:25px;\n"
"background:#31b0d5;\n"
"color:#fff;\n"
"border-image:none;\n"
"background: rgba(154, 207, 206,0.5);"));
        le_name_workNum = new QLineEdit(widget);
        le_name_workNum->setObjectName(QStringLiteral("le_name_workNum"));
        le_name_workNum->setGeometry(QRect(300, 120, 251, 31));
        le_name_workNum->setStyleSheet(QLatin1String("border-radius: 10px;\n"
"border: 1px solid #4288CE;\n"
"background:rgba(0,0,0,0.2);\n"
"color:#fff;\n"
"border-image:none;\n"
"\n"
"\n"
"\n"
"\n"
""));
        le_name_workNum->setAlignment(Qt::AlignCenter);
        le_pwd = new QLineEdit(widget);
        le_pwd->setObjectName(QStringLiteral("le_pwd"));
        le_pwd->setGeometry(QRect(300, 180, 251, 31));
        le_pwd->setStyleSheet(QLatin1String("border-radius: 10px;\n"
"border: 1px solid #4288CE;\n"
"background:rgba(0,0,0,0.2);\n"
"color:#fff;\n"
"border-image:none;\n"
""));
        le_pwd->setAlignment(Qt::AlignCenter);
        pb_daka = new QPushButton(widget);
        pb_daka->setObjectName(QStringLiteral("pb_daka"));
        pb_daka->setGeometry(QRect(470, 250, 81, 31));
        pb_daka->setCursor(QCursor(Qt::PointingHandCursor));
        pb_daka->setStyleSheet(QLatin1String("background: rgba(154, 207, 206,0.5);\n"
"color: rgb(255, 255, 255);\n"
"border:none;\n"
"border-radius:7px;\n"
"cursor:pointer;\n"
"border-image:none;\n"
""));
        pb_login = new QPushButton(widget);
        pb_login->setObjectName(QStringLiteral("pb_login"));
        pb_login->setGeometry(QRect(470, 300, 81, 31));
        pb_login->setCursor(QCursor(Qt::PointingHandCursor));
        pb_login->setStyleSheet(QLatin1String("background: rgba(154, 207, 206,0.5);\n"
"color: rgb(255, 255, 255);\n"
"border:none;\n"
"border-radius:7px;\n"
"cursor:pointer;\n"
"border-image:none;"));
        mytime = new QLabel(widget);
        mytime->setObjectName(QStringLiteral("mytime"));
        mytime->setGeometry(QRect(310, 250, 91, 21));
        mytime->setStyleSheet(QLatin1String("border-image:none;\n"
"font: 14pt \"ADMUI3Lg\";\n"
"color:#fff;\n"
"background:rgba(0,0,0,0);"));
        register_company_message_2 = new QLabel(widget);
        register_company_message_2->setObjectName(QStringLiteral("register_company_message_2"));
        register_company_message_2->setGeometry(QRect(320, 460, 221, 20));
        register_company_message_2->setStyleSheet(QLatin1String("color: rgb(170, 170, 127);\n"
"border-image:none;"));
        register_choose_login_way->raise();
        pb_daka->raise();
        pb_login->raise();
        mytime->raise();
        le_name_workNum->raise();
        le_pwd->raise();
        register_company_message_2->raise();

        retranslateUi(userwork);

        QMetaObject::connectSlotsByName(userwork);
    } // setupUi

    void retranslateUi(QWidget *userwork)
    {
        userwork->setWindowTitle(QApplication::translate("userwork", "Form", 0));
        register_choose_login_way->setText(QApplication::translate("userwork", "\347\225\214\351\235\242", 0));
        le_name_workNum->setPlaceholderText(QApplication::translate("userwork", "\345\247\223\345\220\215\346\210\226\345\267\245\345\217\267", 0));
        le_pwd->setPlaceholderText(QApplication::translate("userwork", "\345\257\206\347\240\201", 0));
        pb_daka->setText(QApplication::translate("userwork", "\346\211\223\345\215\241", 0));
        pb_login->setText(QApplication::translate("userwork", "\347\231\273\345\275\225", 0));
        mytime->setText(QApplication::translate("userwork", "TextLabel", 0));
        register_company_message_2->setText(QApplication::translate("userwork", "2682178536@qq.com\345\256\242\346\210\267QQ\357\274\2322682178536", 0));
    } // retranslateUi

};

namespace Ui {
    class userwork: public Ui_userwork {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERWORK_H
