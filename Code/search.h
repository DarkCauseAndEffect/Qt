#ifndef SEARCH_H
#define SEARCH_H

#include <QDialog>

namespace Ui {
class Search;
}

class Search : public QDialog
{
    Q_OBJECT

public:
    explicit Search(Search *search, QWidget *parent = nullptr);
    ~Search();

    Search* search;

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Search *ui;
};

#endif // SEARCH_H
