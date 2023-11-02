#include"Teacher.h"
#include "teacherdialog.h"
#include "ui_Teacherdialog.h"

TeacherDialog::TeacherDialog(Teacher* teacher, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TeacherDialog)
{
    ui->setupUi(this);
    this->teacher=teacher;

    if(teacher)
    {
        ui->lineId->setText(QString("%1").arg(teacher->id));
        ui->lineEditName->setText(teacher->name);
        ui->lineEditProfessionalTitle->setText(teacher->professionalTitle);
        ui->lineEditEducation->setText(teacher->education);
        ui->lineEditSalary->setText(QString("%1").arg(teacher->salary));
        ui->dateEdit->setDate(teacher->date);
        ui->checkBoxSex->setChecked(teacher->sex);
        ui->checkBoxMarried->setChecked(teacher->married);
    }
}

TeacherDialog::~TeacherDialog()
{
    delete ui;
}

void TeacherDialog::on_buttonBox_accepted()
{
    if(!teacher) teacher=new Teacher;

    teacher->id=ui->lineId->text().toInt();
    teacher->name=ui->lineEditName->text();
    teacher->date=ui->dateEdit->date();
    teacher->professionalTitle=ui->lineEditProfessionalTitle->text();
    teacher->education=ui->lineEditEducation->text();
    teacher->salary=ui->lineEditSalary->text().toFloat();
    teacher->sex=ui->checkBoxSex->checkState();
    teacher->married=ui->checkBoxMarried->checkState();
}
