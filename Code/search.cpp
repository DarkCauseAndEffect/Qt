#include "search.h"
#include "ui_search.h"

Search::Search(Search* search, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Search)
{
    ui->setupUi(this);
    this->search = search;
}

Search::~Search()
{
    delete ui;
}

void Search::on_buttonBox_accepted()
{

}
