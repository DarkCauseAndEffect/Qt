#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QList>
#include"Teacher.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QList<Teacher*> teacherArray;

    void showTeacher(int row,Teacher* teacher);
    Teacher* getTeacher(int id);
    bool removeSportMan(int id);
    void showClasses(int row,Classes* classes);
    void removeAllData();

private slots:
    void on_pushButtonAddTeacher_clicked();

    void on_pushButtonExit_clicked();

    void on_pushButtonAddTeachingInformation_clicked();

    void on_actionOpen_file_triggered();

    void on_actionSave_file_as_triggered();

    void on_actionSave_file_triggered();

    void on_actionId_triggered();

private:
    Ui::MainWindow *ui;
    QString pathName;
};
#endif // MAINWINDOW_H
