#include "searchresultdialog.h"
#include "ui_searchresultdialog.h"

SearchResultDialog::SearchResultDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchResultDialog)
{
    ui->setupUi(this);
}

SearchResultDialog::~SearchResultDialog()
{
    delete ui;
}

void SearchResultDialog::on_buttonBox_accepted()
{
    close();
}
