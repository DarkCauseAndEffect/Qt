#include "iddialog.h"
#include "ui_iddialog.h"
#include"searchresultdialog.h"
#include"mainwindow.h"

IdDialog::IdDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IdDialog)
{
    ui->setupUi(this);
}

IdDialog::~IdDialog()
{
    delete ui;
}

void IdDialog::on_buttonBox_accepted()
{
    ui->comboBoxId->setCurrentIndex(Id);
    int number=0;
    for(int i = 0 ; i< 100; i++)
    {

    }
    if(!number)
    {
        SearchResultDialog dlg(this);
        dlg.setWindowTitle("搜索结果");
        if(dlg.exec() == QDialog::Accepted)
        {
        }
    }
}
