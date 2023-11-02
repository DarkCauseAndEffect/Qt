#ifndef CLASSES_H
#define CLASSES_H

#include <QDataStream>
#include <QString>

class Classes
{
public:
    Classes();
    QString week;//授课时为星期几
    QString time;//授课为第几节课
    QString teachingClass;//授课班级

    friend QDataStream& operator<<(QDataStream& ds,Classes& classes)
    {
        ds<<classes.week<<classes.time<<classes.teachingClass;
        return ds;
    }
    friend QDataStream& operator>>(QDataStream& ds,Classes& classes)
    {
        ds>>classes.week<<classes.time<<classes.teachingClass;
        return ds;
    }
};

#endif // CLASSES_H
