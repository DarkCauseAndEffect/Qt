#include "classesdialog.h"
#include "ui_classesdialog.h"

ClassesDialog::ClassesDialog(Classes* classes, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClassesDialog)
{
    ui->setupUi(this);
    this->classes = classes;
    if(classes)
    {
        ui->comboBoxWeek->setCurrentText(classes->week);
        ui->comboBoxTime->setCurrentText(classes->time);
        ui->comboBoxTeachingclasses->setCurrentText(classes->teachingClass);
    }
}

ClassesDialog::~ClassesDialog()
{
    delete ui;
}

void ClassesDialog::on_buttonBox_accepted()
{
    if(!classes)
        classes = new Classes;
    classes->week = ui->comboBoxWeek->currentText();
    classes->time = ui->comboBoxTime->currentText();
    classes->teachingClass = ui->comboBoxTeachingclasses->currentText();
}
