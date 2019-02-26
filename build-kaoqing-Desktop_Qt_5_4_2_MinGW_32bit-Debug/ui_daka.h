/********************************************************************************
** Form generated from reading UI file 'daka.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DAKA_H
#define UI_DAKA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_daka
{
public:
    QWidget *widget;
    QLabel *mytime;
    QLabel *show_state;
    QPushButton *pb_work_state;

    void setupUi(QWidget *daka)
    {
        if (daka->objectName().isEmpty())
            daka->setObjectName(QStringLiteral("daka"));
        daka->resize(395, 394);
        daka->setStyleSheet(QLatin1String("border-radius:10px;\n"
"\n"
"color:#fff;"));
        widget = new QWidget(daka);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(-1, -6, 401, 401));
        widget->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/Image/bg1.jpg);"));
        mytime = new QLabel(widget);
        mytime->setObjectName(QStringLiteral("mytime"));
        mytime->setGeometry(QRect(10, 150, 371, 61));
        mytime->setStyleSheet(QString::fromUtf8("border-image:none;\n"
"font-family: \"\351\273\221\344\275\223\";\n"
"font-size:60px;\n"
"font-weight:1000;\n"
"text-align:center;"));
        mytime->setAlignment(Qt::AlignCenter);
        show_state = new QLabel(widget);
        show_state->setObjectName(QStringLiteral("show_state"));
        show_state->setGeometry(QRect(10, 40, 381, 31));
        show_state->setStyleSheet(QStringLiteral("border-image:none;"));
        show_state->setAlignment(Qt::AlignCenter);
        pb_work_state = new QPushButton(widget);
        pb_work_state->setObjectName(QStringLiteral("pb_work_state"));
        pb_work_state->setGeometry(QRect(290, 340, 75, 23));
        pb_work_state->setStyleSheet(QLatin1String("background-color: rgb(85, 170, 0);\n"
"color: rgb(255, 255, 255);\n"
"border:none;\n"
"border-image:none;\n"
""));

        retranslateUi(daka);

        QMetaObject::connectSlotsByName(daka);
    } // setupUi

    void retranslateUi(QWidget *daka)
    {
        daka->setWindowTitle(QApplication::translate("daka", "Form", 0));
        mytime->setText(QApplication::translate("daka", "time", 0));
        show_state->setText(QApplication::translate("daka", "\346\211\223\345\215\241", 0));
        pb_work_state->setText(QApplication::translate("daka", "\344\270\212\347\217\255", 0));
    } // retranslateUi

};

namespace Ui {
    class daka: public Ui_daka {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DAKA_H
