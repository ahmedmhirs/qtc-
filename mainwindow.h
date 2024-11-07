#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "article.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ajouter_clicked();
    void on_modifier_clicked();
    void on_tableView_2_clicked(const QModelIndex &index);

    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
    Article a;
};

#endif // MAINWINDOW_H
