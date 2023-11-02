#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QStyleFactory>
#include <QFileDialog>
#include"TeacherDialog.h"
#include"classesdialog.h"
#include"iddialog.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

Teacher* MainWindow::getTeacher(int id)
{
    for(int i=0; i<teacherArray.length(); i++)
    {
        if(teacherArray[i]->id == id)
        {
            return teacherArray[i];
        }
    }
    return NULL;
}

bool MainWindow::removeSportMan(int id)
{
    for(int i=0; i<teacherArray.length(); i++)
    {
        if(teacherArray[i]->id == id)
        {
            delete  teacherArray[i];
           teacherArray.removeAt(i);
            return true;
        }
    }
    return false;
}

void MainWindow::showTeacher(int row, Teacher *teacher)
{
    if(row<0||!teacher) return;
    ui->tableWidgetTeacher->insertRow(row);
    ui->tableWidgetTeacher->setItem(row,0,new QTableWidgetItem(QString("%1").arg(teacher->id)));
    ui->tableWidgetTeacher->setItem(row,1,new QTableWidgetItem(teacher->name));
    ui->tableWidgetTeacher->setItem(row,2,new QTableWidgetItem(teacher->sex?"男":"女"));
    ui->tableWidgetTeacher->setItem(row,3,new QTableWidgetItem(teacher->date.toString("yyyy-MM-dd")));
    ui->tableWidgetTeacher->setItem(row,4,new QTableWidgetItem(teacher->professionalTitle));
    ui->tableWidgetTeacher->setItem(row,5,new QTableWidgetItem(teacher->education));
    ui->tableWidgetTeacher->setItem(row,6,new QTableWidgetItem(QString::number(teacher->salary,'f',2)));
    ui->tableWidgetTeacher->setItem(row,7,new QTableWidgetItem(teacher->married?"是":"否"));

    QPushButton* pushButton = new QPushButton("修改", this);
    ui->tableWidgetTeacher->setCellWidget(row,8,pushButton);
    connect(pushButton,&QPushButton::clicked,
            [=]()
    {
        int row = ui->tableWidgetTeacher->currentRow();
        int id = ui->tableWidgetTeacher->item(row,0)->text().toInt();
        Teacher* teacher = getTeacher(id);
        TeacherDialog dlg(teacher,this);
        if(dlg.exec() == QDialog::Accepted)
        {
            ui->tableWidgetTeacher->setItem(row,0,new QTableWidgetItem(QString("%1").arg(teacher->id)));
            ui->tableWidgetTeacher->setItem(row,1,new QTableWidgetItem(teacher->name));
            ui->tableWidgetTeacher->setItem(row,2,new QTableWidgetItem(teacher->sex?"男":"女"));
            ui->tableWidgetTeacher->setItem(row,3,new QTableWidgetItem(teacher->date.toString("yyyy-MM-dd")));
            ui->tableWidgetTeacher->setItem(row,4,new QTableWidgetItem(teacher->professionalTitle));
            ui->tableWidgetTeacher->setItem(row,5,new QTableWidgetItem(teacher->education));
            ui->tableWidgetTeacher->setItem(row,6,new QTableWidgetItem(QString::number(teacher->salary,'f',2)));
            ui->tableWidgetTeacher->setItem(row,7,new QTableWidgetItem(teacher->married?"是":"否"));
        }
    });

    pushButton = new QPushButton("删除",this);
    ui->tableWidgetTeacher->setCellWidget(row,9,pushButton);
    connect(pushButton,&QPushButton::clicked,
            [=]()
    {
        QMessageBox box;
        if(box.question(this,"删除教师信息","确定要删除该教师的所有信息吗？") == QMessageBox::Yes)
        {
            int row = ui->tableWidgetTeacher->currentRow();
            removeSportMan(ui->tableWidgetTeacher->item(row,0)->text().toInt());
            ui->tableWidgetTeacher->removeRow(row);
        }
    });

    pushButton = new QPushButton("授课信息",this);
    ui->tableWidgetTeacher->setCellWidget(row,10,pushButton);
    connect(pushButton,&QPushButton::clicked,
            [=]()
    {
        ui->stackedWidget->setCurrentIndex(1);
        int row = ui->tableWidgetTeacher->currentRow();
        int id = ui->tableWidgetTeacher->item(row,0)->text().toInt();
        Teacher* teacher = getTeacher(id);
        if(teacher)
        {
            int rows = ui->tableWidgetClasses->rowCount();
            for(int i=0; i<rows; i++)
                ui->tableWidgetClasses->removeRow(0);

            for(int i=0; i<teacher->classesArray.length(); i++)
                showClasses(i,teacher->classesArray[i]);
        }
    });
}

void MainWindow::showClasses(int row, Classes *classes)
{
    if(row<0 || !classes) return;
    ui->tableWidgetClasses->insertRow(row);
    ui->tableWidgetClasses->setItem(row,0,new QTableWidgetItem(classes->week));
    ui->tableWidgetClasses->setItem(row,1,new QTableWidgetItem(classes->time));
    ui->tableWidgetClasses->setItem(row,2,new QTableWidgetItem(classes->teachingClass));

    QPushButton* pushButton = new QPushButton("修改",this);
    ui->tableWidgetClasses->setCellWidget(row,3,pushButton);
    connect(pushButton,&QPushButton::clicked,
            [=]()
    {
        int row = ui->tableWidgetTeacher->currentRow();
        int id = ui->tableWidgetTeacher->item(row,0)->text().toInt();
        Teacher* teacher = getTeacher(id);

        row = ui->tableWidgetClasses->currentRow();
        QString week = ui->tableWidgetClasses->item(row,0)->text();
        QString time = ui->tableWidgetClasses->item(row,1)->text();
        QString teachingClass = ui->tableWidgetClasses->item(row,2)->text();

        Classes* classes = teacher->getClasses(week, time, teachingClass);
        ClassesDialog dlg(classes,this);
        if(dlg.exec() == QDialog::Accepted)
        {
            ui->tableWidgetClasses->setItem(row,0,new QTableWidgetItem(classes->week));
            ui->tableWidgetClasses->setItem(row,1,new QTableWidgetItem(classes->time));
            ui->tableWidgetClasses->setItem(row,2,new QTableWidgetItem(classes->teachingClass));
        }
    });

    pushButton = new QPushButton("删除",this);
    ui->tableWidgetClasses->setCellWidget(row,4,pushButton);
    connect(pushButton,&QPushButton::clicked,
            [=]()
    {
        QMessageBox box;
        if(box.question(this,"删除该课程信息","确信要删除吗？") == QMessageBox::Yes)
        {
            int row = ui->tableWidgetTeacher->currentRow();
            int id = ui->tableWidgetTeacher->item(row,0)->text().toInt();
            Teacher* teacher = getTeacher(id);
            row = ui->tableWidgetClasses->currentRow();
            QString week = ui->tableWidgetClasses->item(row,0)->text();
            QString time = ui->tableWidgetClasses->item(row,1)->text();
            QString teachingClass = ui->tableWidgetClasses->item(row,2)->text();
            teacher->removeClasses(week, time, teachingClass);
            ui->tableWidgetClasses->removeRow(row);
        }
    });
}

void MainWindow::removeAllData()
{
    for(int i=0; i<teacherArray.length(); i++)
    {
       delete  teacherArray[i];
    }
    teacherArray.clear();
}

void MainWindow::on_pushButtonAddTeacher_clicked()
{
    TeacherDialog dlg(NULL,this);
    dlg.setWindowTitle("添加教师");
    if(dlg.exec() == QDialog::Accepted)
    {
        teacherArray.append(dlg.teacher);
        showTeacher(teacherArray.length()-1,dlg.teacher);
    }
}

void MainWindow::on_pushButtonExit_clicked()
{
    close();
}

void MainWindow::on_pushButtonAddTeachingInformation_clicked()
{
    ClassesDialog dlg(NULL,this);
    dlg.setWindowTitle("增加课程信息");
    if(dlg.exec() == QDialog::Accepted)
    {
        int row = ui->tableWidgetTeacher->currentRow();
        int id = ui->tableWidgetTeacher->item(row,0)->text().toInt();
        Teacher* teacher = getTeacher(id);
        if(teacher)
        {
            teacher->classesArray.append(dlg.classes);
            showClasses(ui->tableWidgetClasses->rowCount(),dlg.classes);
        }
    }
}

void MainWindow::on_actionOpen_file_triggered()
{
    QString path = QFileDialog::getOpenFileName(this,"Open","../");
    if(!path.isEmpty())
    {
        QFile file;
        file.setFileName(path);

        if(file.open(QIODevice::ReadOnly))
        {
            for(int i=0; i<teacherArray.length();i++)
                ui->tableWidgetTeacher->removeRow(0);
            removeAllData();

            QDataStream stream(&file);
            int length;
            stream>>length;
            for(int i=0; i<length; i++)
            {
                Teacher* sportMan = new Teacher;
                stream>>*sportMan;
                teacherArray.append(sportMan);
            }
            file.close();

            for(int i=0; i<teacherArray.length(); i++)
                showTeacher(i,teacherArray[i]);
        }
        pathName = path;
    }
}

void MainWindow::on_actionSave_file_as_triggered()
{
    QString path = QFileDialog::getSaveFileName(this,"Save as","../");
    if(!path.isEmpty())
    {
        QFile file;
        file.setFileName(path);

        if(file.open(QIODevice::WriteOnly))
        {
            QDataStream stream(&file);
            int length = teacherArray.length();
            stream<<length;
            for(int i=0; i<length; i++)
                stream<<*teacherArray[i];
            file.close();
        }
        pathName = path;
    }
}

void MainWindow::on_actionSave_file_triggered()
{
    if(!pathName.isEmpty())
    {
       QFile file;
       file.setFileName(pathName);
       if(file.open(QIODevice::WriteOnly))
       {
           QDataStream stream(&file);
           int length = teacherArray.length();
           stream<<length;
           for(int i=0; i<length; i++)
               stream<<*teacherArray[i];
           file.close();
       }
   }
   else
      on_actionSave_file_triggered();
}

void MainWindow::on_actionId_triggered()
{
    IdDialog dlg(this);
    dlg.setWindowTitle("筛选编号");
    if(dlg.exec() == QDialog::Accepted)
    {
    }
}
