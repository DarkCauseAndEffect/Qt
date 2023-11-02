#ifndef TEACHER_H
#define TEACHER_H

#include <QDataStream>
#include <QDate>
#include <QList>
#include <QString>
#include"Classes.h"

class Teacher
{
public:
    Teacher();
    int id;
    QString name;
    bool sex;
    QDate date;
    QString professionalTitle;
    QString education;
    float salary;
    bool married;
    QList<Classes*>classesArray;

    Classes* getClasses(QString week, QString time, QString teachingClass);
    bool removeClasses(QString week, QString time, QString teachingClass);


    friend QDataStream& operator<<(QDataStream& ds,Teacher& teacher)
    {
        int length = teacher.classesArray.length();
        ds<<teacher.id<<teacher.name<<teacher.sex<<teacher.date<<teacher.professionalTitle<<teacher.education<<teacher.salary<<teacher.married<<length;
        for(int i=0; i<length; i++)
            ds<<*teacher.classesArray[i];
        return ds;
    }
    friend QDataStream& operator>>(QDataStream& ds,Teacher& teacher)
    {
        int length;
        ds>>teacher.id>>teacher.name>>teacher.sex>>teacher.date>>teacher.professionalTitle>>teacher.education>>teacher.salary>>teacher.married>>length;
        for(int i=0; i<length; i++)
        {
            Classes* classes = new Classes;
            ds>>*classes;
           teacher.classesArray.append(classes);
        }
        return ds;
    }
};

#endif // TEACHER_H
