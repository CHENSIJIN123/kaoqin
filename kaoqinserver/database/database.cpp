#include "database.h"
#include <QDebug>
#include <QMessageBox>
#include <QSqlQuery>

database::database()
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("kaoqing.db");
    if(!db.open())
    {
        qDebug()<<"open failed!";
    }
    else
    {
        qDebug()<<"成功连接数据库";
    }

}

database::~database()
{
    QSqlDatabase::database().close();
}
