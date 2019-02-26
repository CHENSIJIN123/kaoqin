#include "docxml.h"
#include <QFile>
#include <QDomDocument>  //文件
#include <QDomProcessingInstruction>  //格式头
#include <QDomElement>    //元素
#include <QTextStream>
#include <QDateTime>
#include "register_company.h"
#include <QDebug>
#include <QDomElement>
#define cout qDebug()<<"["<<__FILE__<<":"<<__LINE__<<"]"

docxml::docxml()
{

}

void docxml::createXML(QString filepath)
{
    QFile file(filepath);
    if(true == file.exists())  //如果文件存在就不创建
    {
        cout << "文件已经存在";
        return;
    }else
    {
        //不存在则创建
        //只写方式打开
        bool isOK = file.open(QIODevice::WriteOnly);
        if(true == isOK)   //如果打开成功
        {
            //创建XML文档对象
            QDomDocument doc;
            //创建xml头部格式
            QDomProcessingInstruction ins;
            ins = doc.createProcessingInstruction("xml","version=\'1.0\' encoding=\'UTF-8\'");

            //追加元素
            doc.appendChild(ins);

            //创建根节点元素
            QDomElement root = doc.createElement("公司信息");

            //追加元素
            doc.appendChild(root);

            //保存
            QTextStream stream(&file); //文本流关联文件
            doc.save(stream,4);  //4代表缩进字符

            file.close();  //关闭文件

        }else
        {
            cout << "writeonly error";
            return;
        }
    }
}

void docxml::appendXML(QString filepath,QString s)
{
    QFile file(filepath);
    bool isOK = file.open(QIODevice::ReadOnly);
    if(true == isOK)
    {
        //file和xml文档指针关联
        QDomDocument doc;
        bool isOK = doc.setContent(&file);
        if(true == isOK)   //如果关联成功
        {
            file.close();
            //获取根节点元素
            QDomElement root = doc.documentElement();

            QDomNodeList list = root.childNodes();
            for(int i = 0; i < list.size(); i++)
            {
                QDomElement element = list.at(i).toElement();
                if(element.attribute("name") == s)  //已经存在该公司，则跳出去
                {
                    return;
                }
            }
            //创建公司子节点
            QDomElement dateELe = doc.createElement("公司");

            //创建name的属性
            QDomAttr nameAttr = doc.createAttribute("name");
            //设置属性的值
            nameAttr.setNodeValue(register_company::company_name);
            //关联子节点和属性
            dateELe.setAttributeNode(nameAttr);
            //把公司节点追加到根节点的地方
            root.appendChild(dateELe);

            bool isOK = file.open(QIODevice::WriteOnly);
            if(true == isOK)
            {
                QTextStream stream(&file);
                doc.save(stream,4);
                file.close();
            }
        }else{
            cout << "setcontent error";
            return;
        }
    }else
    {
        cout << "readonly error";
        return;
    }
}

void docxml::appendXML(QString filepath, QString s1,QString s2)
{
    QFile file(filepath);
    bool isOK = file.open(QIODevice::ReadOnly);
    if(true == isOK)
    {
        //file和xml文档指针关联
        QDomDocument doc;
        bool isOK = doc.setContent(&file);
        if(true == isOK)   //如果关联成功
        {
            file.close();
            //获取根节点元素
            QDomElement root = doc.documentElement();

            QDomNodeList list = root.childNodes();
            for(int i = 0; i < list.size(); i++)
            {
                QDomElement element = list.at(i).toElement();
                if(element.attribute("name") == s1)  //已经存在该公司，则跳出去
                {
                    writeXML(doc,element,s2);
                }
            }
            bool isOK = file.open(QIODevice::WriteOnly);
            if(true == isOK)
            {
                QTextStream stream(&file);
                doc.save(stream,4);
                file.close();
            }
        }else{
            cout << "setcontent error";
            return;
        }
    }else
    {
        cout << "readonly error";
        return;
    }
}

void docxml::writeXML(QDomDocument &doc,QDomElement &root,QString s1)
{                                                         //S1员工名字
    //当前时间获取
    QDateTime time = QDateTime::currentDateTime();
    QString timestr = time.toString("yy年MM月dd日");

    //创建日期节点元素
    QDomElement employeeEL = doc.createElement("日期");
    QDomAttr nameAttr = doc.createAttribute("time");
    nameAttr.setNodeValue(timestr);
    employeeEL.setAttributeNode(nameAttr);
    root.appendChild(employeeEL);

    //创建员工节点元素
    QDomElement empl = doc.createElement("员工");
    QDomAttr naAttr = doc.createAttribute("name");
    naAttr.setNodeValue(s1);
    empl.setAttributeNode(naAttr);
    employeeEL.appendChild(empl);

    //创键上下班节点元素
    QDomElement starttowork;
    if(time.toString("hh").toInt() < 12 && time.toString("hh").toInt() > 6)
    {
        starttowork = doc.createElement("上班");
    }else
    {
        starttowork = doc.createElement("下班");
    }
    empl.appendChild(starttowork);
}

void docxml::readXML(QString filepath,QStringList &fList)
{
    QFile file(filepath);
    bool isOK = file.open(QIODevice::ReadOnly);
    if(true == isOK)
    {
        //file和xml文档指针关联
        QDomDocument doc;
        bool isOK = doc.setContent(&file);
        if(isOK)
        {
            //获取根节点元素
            QDomElement root = doc.documentElement();
            file.close();

            if(root.hasChildNodes())
            {
                //取出根节点的所有子节点
                QDomNodeList list = root.childNodes();
                for(int i = 0; i < list.size(); i++)
                {
                    //转换为元素
                    QDomElement com = list.at(i).toElement();
                    QString companyName = com.attribute("name");
                    fList.append(companyName);
                }

            }else
            {
                cout << "没有子节点";
                return;
            }
        }else
        {
            cout <<"setcontent error";
            return;
        }
    }else
    {
        cout << "readonly error";
        return;
    }
}


QString docxml::readXML(QString filepath, QString comName,QString empName)
{

    QFile file(filepath);
    bool isOK = file.open(QIODevice::ReadOnly);
    if(true == isOK)
    {
        //file和xml文档指针关联
        QDomDocument doc;
        bool isOK = doc.setContent(&file);
        if(isOK)
        {
            //获取根节点元素
            QDomElement root = doc.documentElement();
            file.close();

            QDateTime date = QDateTime::currentDateTime();
            QString dateStr = date.toString("yy年MM月dd日");

            if(root.hasChildNodes())
            {
                QDomNodeList companyList = root.childNodes();
                for(int i = 0; i < companyList.size(); i++)
                {
                    QDomElement company = companyList.at(i).toElement();
                    if(company.attribute("name") == comName)   //公司名匹配
                    {
                        if(company.hasChildNodes())   //公司节点下有没有子节点
                        {
                            QDomElement lastEle = company.lastChildElement();
                            cout << lastEle.attribute("time") << ":     "<<dateStr;
                            if(lastEle.attribute("time") == dateStr)   //如果有今天的日期
                            {
                                if(lastEle.hasChildNodes()) //该日期下有子节点
                                {
                                    QDomNodeList employeeList = lastEle.childNodes();
                                    for(int j = 0; j < employeeList.size();j++)
                                    {
                                        QDomElement employName = employeeList.at(j).toElement();
                                        if(employName.attribute("name") == empName)
                                        {
                                            //有这个人的打卡信息
                                            if(employName.hasChildNodes())
                                            {
                                                QDateTime date = QDateTime::currentDateTime();
                                                QString dateStr = date.toString("hh");
                                                QDomNodeList workList = employName.childNodes();
                                                for(int m = 0;m < workList.size();m++)
                                                {
                                                    QDomElement work = workList.at(m).toElement();
                                                    if(dateStr.toInt() < 12 && dateStr.toInt() > 06)
                                                    {
                                                        //判断有没有上班的打卡记录
                                                        if(work.tagName() == "上班")
                                                        {
                                                            return "上班";
                                                        }
                                                    }else
                                                    {
                                                        //判断有没有下班的打卡记录
                                                        if(work.tagName() == "下班")
                                                        {
                                                            return "下班";
                                                        }
                                                    }
                                                }
                                            }else
                                            {
                                                cout <<"他今天没有打卡";
                                                return "";
                                            }
                                        }
                                    }

                                }else
                                {
                                    cout << "今天还没有人打卡";
                                    return "";
                                }
                            }else
                            {
                                cout <<"没有今天的日期";
                                return "";
                            }
                        }else
                        {
                            cout << "腾讯下没有子节点";
                            return "";
                        }
                    }else
                    {
                        cout <<"没有该公司";
                        return "";
                    }
                }

            }else
            {
                cout << "没有子节点";
                return "";
            }
        }else
        {
            cout <<"setcontent error";
            return "";
        }
    }else
    {
        cout << "readonly error";
        return "";
    }
}
