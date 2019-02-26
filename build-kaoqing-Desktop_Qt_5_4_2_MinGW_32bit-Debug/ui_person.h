/********************************************************************************
** Form generated from reading UI file 'person.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERSON_H
#define UI_PERSON_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_person
{
public:
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QWidget *widget;
    QPushButton *pb_apply_budaka;
    QPushButton *pb_apply_vacation;
    QPushButton *pb_apply_jiaban;
    QPushButton *pb_delete;
    QTableWidget *tableWidget;
    QWidget *tab_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QCheckBox *checkBox;
    QLabel *label_4;
    QLineEdit *le_name;
    QLineEdit *currentpsw;
    QLabel *label_5;
    QLineEdit *newpsw;
    QLabel *label_6;
    QLineEdit *querenpsw;
    QPushButton *pb_save;
    QPushButton *pb_return;
    QLabel *lb_currentpsw;
    QLabel *lb_queren;
    QLabel *lb_show;
    QWidget *tab_3;

    void setupUi(QWidget *person)
    {
        if (person->objectName().isEmpty())
            person->setObjectName(QStringLiteral("person"));
        person->resize(935, 514);
        widget_2 = new QWidget(person);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(0, 0, 941, 521));
        widget_2->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/Image/background.jpg);"));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabWidget = new QTabWidget(widget_2);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setStyleSheet(QStringLiteral(""));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        widget = new QWidget(tab);
        widget->setObjectName(QStringLiteral("widget"));
        pb_apply_budaka = new QPushButton(widget);
        pb_apply_budaka->setObjectName(QStringLiteral("pb_apply_budaka"));
        pb_apply_budaka->setGeometry(QRect(480, 10, 75, 23));
        pb_apply_budaka->setStyleSheet(QLatin1String("border: 1px solid #4288CE;\n"
"background: rgba(154, 207, 206,0.5);\n"
"color: rgb(255, 255, 255);\n"
"border:none;\n"
"border-radius:7px;\n"
"cursor:pointer;\n"
"border-image:none;"));
        pb_apply_vacation = new QPushButton(widget);
        pb_apply_vacation->setObjectName(QStringLiteral("pb_apply_vacation"));
        pb_apply_vacation->setGeometry(QRect(590, 10, 75, 23));
        pb_apply_vacation->setStyleSheet(QLatin1String("border: 1px solid #4288CE;\n"
"background: rgba(154, 207, 206,0.5);\n"
"color: rgb(255, 255, 255);\n"
"border:none;\n"
"border-radius:7px;\n"
"cursor:pointer;\n"
"border-image:none;"));
        pb_apply_jiaban = new QPushButton(widget);
        pb_apply_jiaban->setObjectName(QStringLiteral("pb_apply_jiaban"));
        pb_apply_jiaban->setGeometry(QRect(700, 10, 75, 23));
        pb_apply_jiaban->setStyleSheet(QLatin1String("border: 1px solid #4288CE;\n"
"background: rgba(154, 207, 206,0.5);\n"
"color: rgb(255, 255, 255);\n"
"border:none;\n"
"border-radius:7px;\n"
"cursor:pointer;\n"
"border-image:none;"));
        pb_delete = new QPushButton(widget);
        pb_delete->setObjectName(QStringLiteral("pb_delete"));
        pb_delete->setGeometry(QRect(800, 10, 75, 23));
        pb_delete->setStyleSheet(QLatin1String("border: 1px solid #4288CE;\n"
"background: rgba(154, 207, 206,0.5);\n"
"color: rgb(255, 255, 255);\n"
"border:none;\n"
"border-radius:7px;\n"
"cursor:pointer;\n"
"border-image:none;"));
        tableWidget = new QTableWidget(widget);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(10, 70, 871, 192));
        tableWidget->setStyleSheet(QLatin1String("border: 1px solid #4288CE;\n"
"background: rgba(154, 207, 206,0.5);\n"
"color: rgb(255, 255, 255);\n"
"border:none;\n"
"border-radius:7px;\n"
"cursor:pointer;\n"
"border-image:none;"));

        gridLayout_2->addWidget(widget, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        label = new QLabel(tab_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 30, 91, 31));
        label->setStyleSheet(QLatin1String("border: 1px solid #4288CE;\n"
"background: rgba(154, 207, 206,0.5);\n"
"color: rgb(255, 255, 255);\n"
"border:none;\n"
"border-radius:7px;\n"
"cursor:pointer;\n"
"border-image:none;"));
        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(90, 90, 54, 12));
        label_2->setStyleSheet(QLatin1String("border: 1px solid #4288CE;\n"
"background: rgba(154, 207, 206,0);\n"
"color: rgb(255, 255, 255);\n"
"border:none;\n"
"border-radius:7px;\n"
"cursor:pointer;\n"
"border-image:none;"));
        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(70, 170, 54, 12));
        label_3->setStyleSheet(QLatin1String("border: 1px solid #4288CE;\n"
"background: rgba(154, 207, 206,0);\n"
"color: rgb(255, 255, 255);\n"
"border:none;\n"
"border-radius:7px;\n"
"cursor:pointer;\n"
"border-image:none;"));
        checkBox = new QCheckBox(tab_2);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(140, 130, 71, 16));
        checkBox->setStyleSheet(QLatin1String("border: 1px solid #4288CE;\n"
"background: rgba(154, 207, 206,0);\n"
"color: rgb(255, 255, 255);\n"
"border:none;\n"
"border-radius:7px;\n"
"cursor:pointer;\n"
"border-image:none;"));
        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(70, 130, 54, 12));
        label_4->setStyleSheet(QLatin1String("border: 1px solid #4288CE;\n"
"background: rgba(154, 207, 206,0);\n"
"color: rgb(255, 255, 255);\n"
"border:none;\n"
"border-radius:7px;\n"
"cursor:pointer;\n"
"border-image:none;"));
        le_name = new QLineEdit(tab_2);
        le_name->setObjectName(QStringLiteral("le_name"));
        le_name->setGeometry(QRect(140, 90, 131, 20));
        le_name->setStyleSheet(QLatin1String("border: 1px solid #4288CE;\n"
"background: rgba(154, 207, 206,0.5);\n"
"color: rgb(255, 255, 255);\n"
"border:none;\n"
"border-radius:7px;\n"
"cursor:pointer;\n"
"border-image:none;"));
        le_name->setReadOnly(true);
        currentpsw = new QLineEdit(tab_2);
        currentpsw->setObjectName(QStringLiteral("currentpsw"));
        currentpsw->setGeometry(QRect(140, 170, 131, 20));
        currentpsw->setStyleSheet(QLatin1String("border: 1px solid #4288CE;\n"
"background: rgba(154, 207, 206,0.5);\n"
"color: rgb(255, 255, 255);\n"
"border:none;\n"
"border-radius:7px;\n"
"cursor:pointer;\n"
"border-image:none;"));
        currentpsw->setReadOnly(true);
        label_5 = new QLabel(tab_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(70, 210, 54, 12));
        label_5->setStyleSheet(QLatin1String("border: 1px solid #4288CE;\n"
"background: rgba(154, 207, 206,0);\n"
"color: rgb(255, 255, 255);\n"
"border:none;\n"
"border-radius:7px;\n"
"cursor:pointer;\n"
"border-image:none;"));
        newpsw = new QLineEdit(tab_2);
        newpsw->setObjectName(QStringLiteral("newpsw"));
        newpsw->setGeometry(QRect(140, 210, 131, 20));
        newpsw->setStyleSheet(QLatin1String("border: 1px solid #4288CE;\n"
"background: rgba(154, 207, 206,0.5);\n"
"color: rgb(255, 255, 255);\n"
"border:none;\n"
"border-radius:7px;\n"
"cursor:pointer;\n"
"border-image:none;"));
        newpsw->setReadOnly(true);
        label_6 = new QLabel(tab_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(60, 250, 71, 16));
        label_6->setStyleSheet(QLatin1String("border: 1px solid #4288CE;\n"
"background: rgba(154, 207, 206,0);\n"
"color: rgb(255, 255, 255);\n"
"border:none;\n"
"border-radius:7px;\n"
"cursor:pointer;\n"
"border-image:none;"));
        querenpsw = new QLineEdit(tab_2);
        querenpsw->setObjectName(QStringLiteral("querenpsw"));
        querenpsw->setGeometry(QRect(140, 250, 131, 20));
        querenpsw->setStyleSheet(QLatin1String("border: 1px solid #4288CE;\n"
"background: rgba(154, 207, 206,0.5);\n"
"color: rgb(255, 255, 255);\n"
"border:none;\n"
"border-radius:7px;\n"
"cursor:pointer;\n"
"border-image:none;"));
        pb_save = new QPushButton(tab_2);
        pb_save->setObjectName(QStringLiteral("pb_save"));
        pb_save->setGeometry(QRect(130, 320, 51, 23));
        pb_save->setStyleSheet(QLatin1String("border: 1px solid #4288CE;\n"
"background: rgba(154, 207, 206,0.5);\n"
"color: rgb(255, 255, 255);\n"
"border:none;\n"
"border-radius:7px;\n"
"cursor:pointer;\n"
"border-image:none;"));
        pb_return = new QPushButton(tab_2);
        pb_return->setObjectName(QStringLiteral("pb_return"));
        pb_return->setGeometry(QRect(210, 320, 51, 23));
        pb_return->setStyleSheet(QLatin1String("border: 1px solid #4288CE;\n"
"background: rgba(154, 207, 206,0.5);\n"
"color: rgb(255, 255, 255);\n"
"border:none;\n"
"border-radius:7px;\n"
"cursor:pointer;\n"
"border-image:none;"));
        lb_currentpsw = new QLabel(tab_2);
        lb_currentpsw->setObjectName(QStringLiteral("lb_currentpsw"));
        lb_currentpsw->setGeometry(QRect(290, 170, 131, 16));
        lb_currentpsw->setStyleSheet(QLatin1String("border: 1px solid #4288CE;\n"
"background: rgba(154, 207, 206,0);\n"
"color: rgb(255, 255, 255);\n"
"border:none;\n"
"border-radius:7px;\n"
"cursor:pointer;\n"
"border-image:none;"));
        lb_queren = new QLabel(tab_2);
        lb_queren->setObjectName(QStringLiteral("lb_queren"));
        lb_queren->setGeometry(QRect(290, 250, 141, 16));
        lb_queren->setStyleSheet(QLatin1String("border: 1px solid #4288CE;\n"
"background: rgba(154, 207, 206,0);\n"
"color: rgb(255, 255, 255);\n"
"border:none;\n"
"border-radius:7px;\n"
"cursor:pointer;\n"
"border-image:none;"));
        lb_show = new QLabel(tab_2);
        lb_show->setObjectName(QStringLiteral("lb_show"));
        lb_show->setGeometry(QRect(100, 370, 141, 51));
        lb_show->setStyleSheet(QLatin1String("border: 1px solid #4288CE;\n"
"background: rgba(154, 207, 206,0);\n"
"color: rgb(255, 255, 255);\n"
"border:none;\n"
"border-radius:7px;\n"
"cursor:pointer;\n"
"border-image:none;"));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tabWidget->addTab(tab_3, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(person);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(person);
    } // setupUi

    void retranslateUi(QWidget *person)
    {
        person->setWindowTitle(QApplication::translate("person", "Form", 0));
        pb_apply_budaka->setText(QApplication::translate("person", "\347\224\263\350\257\267\350\241\245\346\211\223\345\215\241", 0));
        pb_apply_vacation->setText(QApplication::translate("person", "\347\224\263\350\257\267\344\274\221\345\201\207", 0));
        pb_apply_jiaban->setText(QApplication::translate("person", "\347\224\263\350\257\267\345\212\240\347\217\255", 0));
        pb_delete->setText(QApplication::translate("person", "\345\210\240\351\231\244\351\200\211\344\270\255\351\241\271", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("person", "\345\247\223\345\220\215", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("person", "\346\227\245\346\234\237", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("person", "\346\227\266\351\227\264", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("person", "\347\261\273\345\236\213", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("person", "\345\221\230\345\267\245\350\257\264\346\230\216", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("person", "\347\212\266\346\200\201", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("person", "\347\224\263\350\257\267", 0));
        label->setText(QApplication::translate("person", "\344\270\252\344\272\272\350\256\276\347\275\256", 0));
        label_2->setText(QApplication::translate("person", "\345\247\223\345\220\215", 0));
        label_3->setText(QApplication::translate("person", "\345\275\223\345\211\215\345\257\206\347\240\201", 0));
        checkBox->setText(QString());
        label_4->setText(QApplication::translate("person", "\344\277\256\346\224\271\345\257\206\347\240\201", 0));
        label_5->setText(QApplication::translate("person", "\346\226\260\345\257\206\347\240\201", 0));
        label_6->setText(QApplication::translate("person", "\347\241\256\350\256\244\346\226\260\345\257\206\347\240\201", 0));
        pb_save->setText(QApplication::translate("person", "\344\277\235\345\255\230", 0));
        pb_return->setText(QApplication::translate("person", "\350\277\224\345\233\236", 0));
        lb_currentpsw->setText(QString());
        lb_queren->setText(QString());
        lb_show->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("person", "\344\270\252\344\272\272\350\256\276\347\275\256", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("person", "\351\200\200\345\207\272", 0));
    } // retranslateUi

};

namespace Ui {
    class person: public Ui_person {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERSON_H
