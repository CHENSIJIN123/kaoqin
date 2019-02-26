#ifndef DOCXML_H
#define DOCXML_H
#include <QString>
#include <QDomDocument>
#include <QDomElement>

class docxml
{
public:
    docxml();
    static void createXML(QString filepath);  //创建xml空文件
    static void appendXML(QString filepath, QString s);
    static void appendXML(QString filepath, QString s1,QString s2);
    static void readXML(QString filepath,QStringList &fList);
    static QString readXML(QString filepath, QString comName,QString empName);
    static void writeXML(QDomDocument &doc, QDomElement &root, QString s1);
};

#endif // DOCXML_H
