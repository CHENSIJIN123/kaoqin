/********************************************************************************
** Form generated from reading UI file 'increasemanager.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INCREASEMANAGER_H
#define UI_INCREASEMANAGER_H

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

class Ui_increaseManager
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pb_increase;
    QPushButton *pb_cancel;
    QWidget *widget;

    void setupUi(QWidget *increaseManager)
    {
        if (increaseManager->objectName().isEmpty())
            increaseManager->setObjectName(QStringLiteral("increaseManager"));
        increaseManager->resize(278, 173);
        increaseManager->setStyleSheet(QLatin1String("\n"
"color:#fff"));
        label = new QLabel(increaseManager);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 35, 81, 21));
        label->setStyleSheet(QStringLiteral("border-image:none;"));
        lineEdit = new QLineEdit(increaseManager);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(20, 70, 241, 20));
        lineEdit->setStyleSheet(QLatin1String("border-image:none;\n"
"border-radius:8px;\n"
"background:rgba(255,255,255,0.3);\n"
""));
        pb_increase = new QPushButton(increaseManager);
        pb_increase->setObjectName(QStringLiteral("pb_increase"));
        pb_increase->setGeometry(QRect(140, 130, 51, 23));
        pb_increase->setStyleSheet(QLatin1String("border-image:none;\n"
"background-color: rgb(85, 170, 0);\n"
"color: rgb(255, 255, 255);\n"
"border:none;\n"
"border-radius:8px;"));
        pb_cancel = new QPushButton(increaseManager);
        pb_cancel->setObjectName(QStringLiteral("pb_cancel"));
        pb_cancel->setGeometry(QRect(210, 130, 51, 23));
        pb_cancel->setStyleSheet(QLatin1String("border-image:none;\n"
"background-color: rgb(85, 170, 0);\n"
"color: rgb(255, 255, 255);\n"
"border:none;\n"
"border-radius:8px;"));
        widget = new QWidget(increaseManager);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 281, 181));
        widget->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/Image/bg1.jpg);"));
        widget->raise();
        label->raise();
        lineEdit->raise();
        pb_increase->raise();
        pb_cancel->raise();

        retranslateUi(increaseManager);

        QMetaObject::connectSlotsByName(increaseManager);
    } // setupUi

    void retranslateUi(QWidget *increaseManager)
    {
        increaseManager->setWindowTitle(QApplication::translate("increaseManager", "Form", 0));
        label->setText(QApplication::translate("increaseManager", "\351\203\250\351\227\250\345\220\215\347\247\260\357\274\232", 0));
        pb_increase->setText(QApplication::translate("increaseManager", "\346\267\273\345\212\240", 0));
        pb_cancel->setText(QApplication::translate("increaseManager", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class increaseManager: public Ui_increaseManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INCREASEMANAGER_H
