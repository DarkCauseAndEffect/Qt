#include"Teacher.h"

Teacher::Teacher()
{

}

Classes* Teacher::getClasses(QString week, QString time, QString teachingClass)
{
    for(int i=0; i<classesArray.length(); i++)
    {
        if(classesArray[i]->week == week && classesArray[i]->time == time && classesArray[i]->teachingClass == teachingClass)
        {
            return classesArray[i];
        }
    }
    return NULL;
}

bool Teacher::removeClasses(QString week, QString time, QString teachingClass)
{
    for(int i=0; i<classesArray.length(); i++)
    {
        if(classesArray[i]->week == week && classesArray[i]->time == time && classesArray[i]->teachingClass == teachingClass)
        {
            delete classesArray[i];
            classesArray.removeAt(i);
            return true;
        }
    }
    return false;
}
