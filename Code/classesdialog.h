#ifndef CLASSESDIALOG_H
#define CLASSESDIALOG_H

#include <QDialog>
#include"Classes.h"

namespace Ui {
class ClassesDialog;
}

class ClassesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ClassesDialog(Classes* classes, QWidget *parent = nullptr);
    ~ClassesDialog();

    Classes* classes;

private slots:
    void on_buttonBox_accepted();

private:
    Ui::ClassesDialog *ui;
};

#endif // CLASSESDIALOG_H
