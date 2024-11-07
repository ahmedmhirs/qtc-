#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlQuery>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(a.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ajouter_clicked()
{
    Article newArticle;

    // Utilisation des setters individuels au lieu de setArticle
    newArticle.setId(ui->lineEdit_9->text());
    newArticle.setNom(ui->lineEdit_8->text());
    newArticle.setCategorie(ui->lineEdit_3->text());
    newArticle.setStatut(ui->lineEdit_10->text().toInt());
    newArticle.setDateDebut(ui->dateEdit_2->date());
    newArticle.setDateFin(ui->dateEdit_3->date());
    newArticle.setType(ui->lineEdit_11->text());
    newArticle.setEtat(ui->lineEdit_12->text());

    bool success = newArticle.ajouter();
    if(success)
    {
        ui->tableView->setModel(a.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("Ajout effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                    QObject::tr("Ajout non effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
void MainWindow::on_modifier_clicked()
{
    Article modifiedArticle;

    // Utilisation des setters individuels au lieu de setArticle
    modifiedArticle.setId(ui->lineEdit_9->text());
    modifiedArticle.setNom(ui->lineEdit_8->text());
    modifiedArticle.setCategorie(ui->lineEdit_3->text());
    modifiedArticle.setStatut(ui->lineEdit_10->text().toInt());
    modifiedArticle.setDateDebut(ui->dateEdit_2->date());
    modifiedArticle.setDateFin(ui->dateEdit_3->date());
    modifiedArticle.setType(ui->lineEdit_11->text());
    modifiedArticle.setEtat(ui->lineEdit_12->text());

    bool success = modifiedArticle.modifier(ui->lineEdit->text());
    if(success)
    {
        ui->tableView->setModel(a.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("Modification effectuée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                    QObject::tr("Modification non effectuée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_tableView_2_clicked(const QModelIndex &index)
{
    QString id = ui->tableView->model()->data(index.sibling(index.row(), 0)).toString();

    QSqlQuery query;
    query.prepare("SELECT * FROM ARTICLE WHERE ID_A = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next())
    {
        ui->lineEdit_9->setText(query.value("ID_A").toString());
        ui->lineEdit_8->setText(query.value("NOM_A").toString());
        ui->lineEdit_3->setText(query.value("CATEGORIE").toString());
        ui->lineEdit_10->setText(query.value("SATUTS").toString());
        ui->dateEdit_2->setDate(query.value("DATE_ACHA").toDate());
        ui->dateEdit_3->setDate(query.value("DATE_EXPIRATION").toDate());
        ui->lineEdit_11->setText(query.value("TYPE").toString());
        ui->lineEdit_12->setText(query.value("ETAT").toString());
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    QString id = ui->lineEdit->text();
    bool success = a.supprimer(id);
    if(success)
    {
        ui->tableView->setModel(a.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("Suppression effectuée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                    QObject::tr("Suppression non effectuée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

