/********************************************************************************
** Form generated from reading UI file 'apply.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPLY_H
#define UI_APPLY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_apply
{
public:
    QWidget *widget;
    QLabel *label_4;
    QPushButton *pb_queren;
    QPushButton *pb_cancel;
    QLabel *label;
    QDateEdit *dateEdit;
    QLabel *label_2;
    QTimeEdit *timeEdit;
    QLabel *label_3;
    QTextEdit *textEdit;

    void setupUi(QWidget *apply)
    {
        if (apply->objectName().isEmpty())
            apply->setObjectName(QStringLiteral("apply"));
        apply->resize(466, 360);
        widget = new QWidget(apply);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(-4, 0, 471, 361));
        widget->setStyleSheet(QLatin1String("border-image: url(:/new/prefix1/Image/bg1.jpg);\n"
"color:#fff;"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 10, 441, 31));
        label_4->setStyleSheet(QStringLiteral("border-image:none;"));
        label_4->setAlignment(Qt::AlignCenter);
        pb_queren = new QPushButton(widget);
        pb_queren->setObjectName(QStringLiteral("pb_queren"));
        pb_queren->setGeometry(QRect(200, 300, 75, 23));
        pb_queren->setStyleSheet(QLatin1String("border-image:none;\n"
"background-color: rgb(85, 170, 0);\n"
"color: rgb(255, 255, 255);\n"
"border:none;\n"
"border-radius:8px;"));
        pb_cancel = new QPushButton(widget);
        pb_cancel->setObjectName(QStringLiteral("pb_cancel"));
        pb_cancel->setGeometry(QRect(320, 300, 75, 23));
        pb_cancel->setStyleSheet(QLatin1String("background-color: rgb(85, 170, 0);\n"
"color: rgb(255, 255, 255);\n"
"border:none;\n"
"border-image:none;\n"
"border-radius:8px;\n"
""));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 70, 61, 21));
        label->setStyleSheet(QStringLiteral("border-image:none;"));
        dateEdit = new QDateEdit(widget);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(100, 70, 130, 22));
        dateEdit->setStyleSheet(QLatin1String("border-image:none;\n"
"color:#000;\n"
""));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 120, 61, 21));
        label_2->setStyleSheet(QStringLiteral("border-image:none;"));
        timeEdit = new QTimeEdit(widget);
        timeEdit->setObjectName(QStringLiteral("timeEdit"));
        timeEdit->setGeometry(QRect(100, 120, 131, 22));
        timeEdit->setStyleSheet(QLatin1String("border-image:none;\n"
"color:#000;"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 180, 61, 21));
        label_3->setStyleSheet(QStringLiteral("border-image:none;"));
        textEdit = new QTextEdit(widget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(100, 180, 331, 101));
        textEdit->setStyleSheet(QLatin1String("border-image:none;\n"
"color:#000;"));

        retranslateUi(apply);

        QMetaObject::connectSlotsByName(apply);
    } // setupUi

    void retranslateUi(QWidget *apply)
    {
        apply->setWindowTitle(QApplication::translate("apply", "Form", 0));
        label_4->setText(QApplication::translate("apply", "\347\224\263\350\257\267\350\241\245\346\211\223\345\215\241", 0));
        pb_queren->setText(QApplication::translate("apply", "\347\241\256\345\256\232", 0));
        pb_cancel->setText(QApplication::translate("apply", "\345\217\226\346\266\210", 0));
        label->setText(QApplication::translate("apply", "\346\227\245\346\234\237", 0));
        label_2->setText(QApplication::translate("apply", "\346\227\266\351\227\264", 0));
        label_3->setText(QApplication::translate("apply", "\350\257\264\346\230\216", 0));
    } // retranslateUi

};

namespace Ui {
    class apply: public Ui_apply {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPLY_H
