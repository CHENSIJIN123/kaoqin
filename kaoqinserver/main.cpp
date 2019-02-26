#include "widget.h"
#include <QApplication>
#include "database.h"
#include "execsql.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    database db;
    execSql s;
    widget w;
    w.show();

    return a.exec();
}
