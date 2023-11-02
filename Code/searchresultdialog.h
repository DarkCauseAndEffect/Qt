#ifndef SEARCHRESULTDIALOG_H
#define SEARCHRESULTDIALOG_H

#include <QDialog>

namespace Ui {
class SearchResultDialog;
}

class SearchResultDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SearchResultDialog(QWidget *parent = nullptr);
    ~SearchResultDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::SearchResultDialog *ui;
};

#endif // SEARCHRESULTDIALOG_H
