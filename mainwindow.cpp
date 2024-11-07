#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "article.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    refreshTableView();  // Initialiser la vue de la table avec les articles existants
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::refreshTableView()
{
    Article a(1, "Article 1", "Catégorie 1", QDate::currentDate(), QDate::currentDate().addMonths(1), "Active");  // Créer une instance temporaire de 'Article' pour afficher les articles
    ui->tableView_2->setModel(a.afficher());  // Charger les données dans la vue
}

bool MainWindow::validateInputs()
{
    bool valid = true;
    if (ui->lineEdit_9->text().isEmpty()) {
        QMessageBox::warning(this, "Erreur", "L'ID de l'article est requis.");
        valid = false;
    } else if (ui->lineEdit_8->text().isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Le nom de l'article est requis.");
        valid = false;
    } else if (ui->lineEdit_3->text().isEmpty()) {
        QMessageBox::warning(this, "Erreur", "La catégorie de l'article est requise.");
        valid = false;
    }
    // Vérifiez les dates
    if (ui->dateEdit_2->date() > ui->dateEdit_3->date()) {
        QMessageBox::warning(this, "Erreur", "La date de début ne peut pas être après la date de fin.");
        valid = false;
    }

    return valid;
}

void MainWindow::on_ajouter_clicked()
{
    int id=ui->lineEdit_9->text().toInt();
    QString nom =ui->lineEdit_8->text();
    QString catégorie=ui->lineEdit_3->text();
    QDate datedebut=ui->dateEdit_2->date();
    QDate datefin=ui->dateEdit_3->date();
    QString statut =ui->lineEdit_10->text();
     article a(int id, const QString& nom, const QString& catégorie, const QDate& datedebut, const QDate& datefin, const QString& statut);
    if(a.ajout(int id, const QString& nom, const QString& catégorie, const QDate& datedebut, const QDate& datefin, const QString& statut)){

           QMessageBox::information(nullptr, "Ajout", "Ajout avec succès");
        ui->tableView->setModel(a.afficher());
     }
    else{
        QMessageBox::warning(nullptr, "erreur", "Ajout failed");
    }

}
