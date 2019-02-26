#include "register_company.h"
#include <QApplication>
#include "person.h"
#include "apply.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    register_company w;
    w.show();
//    person p;
//    p.show();

    return a.exec();
}
