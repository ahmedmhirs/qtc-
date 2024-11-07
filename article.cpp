#include "article.h"
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>

Article::Article()
    : statut(0), dateDebut(QDate::currentDate()), dateFin(QDate::currentDate())
{
}

Article::Article(const QString& id, const QString& nom, const QString& categorie,
                 int statut, const QDate& dateDebut, const QDate& dateFin,
                 const QString& type, const QString& etat)
    : id(id), nom(nom), categorie(categorie), statut(statut),
      type(type), etat(etat), dateDebut(dateDebut), dateFin(dateFin)
{
}

void Article::setId(const QString& id) {
    if (id.length() <= 20) this->id = id;
}

void Article::setNom(const QString& nom) {
    if (nom.length() <= 20) this->nom = nom;
}

void Article::setCategorie(const QString& categorie) {
    if (categorie.length() <= 20) this->categorie = categorie;
}

void Article::setStatut(int statut) {
    if (statut >= 0) this->statut = statut;
}

void Article::setDateDebut(const QDate& dateDebut) {
    this->dateDebut = dateDebut;
}

void Article::setDateFin(const QDate& dateFin) {
    this->dateFin = dateFin;
}

void Article::setType(const QString& type) {
    if (type.length() <= 20) this->type = type;
}

void Article::setEtat(const QString& etat) {
    if (etat.length() <= 20) this->etat = etat;
}

bool Article::isValid() const {
    return !id.isEmpty() && !nom.isEmpty() && !categorie.isEmpty() &&
           dateDebut.isValid() && dateFin.isValid() && dateDebut <= dateFin;
}

bool Article::ajouter()
{
    if (!isValid()) return false;

    QSqlQuery query;
    query.prepare("INSERT INTO ARTICLE (ID_A, NOM_A, CATEGORIE, DATE_ACHA, "
                  "DATE_EXPIRATION, SATUTS, TYPE, ETAT) "
                  "VALUES (:id, :nom, :categorie, :date_d, :date_f, :status, "
                  ":type, :etat)");

    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":categorie", categorie);
    query.bindValue(":date_d", dateDebut);
    query.bindValue(":date_f", dateFin);
    query.bindValue(":status", statut);
    query.bindValue(":type", type);
    query.bindValue(":etat", etat);

    return query.exec();
}

QSqlQueryModel* Article::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM ARTICLE");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Catégorie"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date d'achat"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date d'expiration"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Statut"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("État"));

    return model;
}

bool Article::supprimer(const QString& id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM ARTICLE WHERE ID_A = :id");
    query.bindValue(":id", id);
    return query.exec();
}

bool Article::modifier(const QString& id)
{
    if (!isValid()) return false;

    QSqlQuery query;
    query.prepare("UPDATE ARTICLE SET NOM_A=:nom, CATEGORIE=:categorie, "
                  "DATE_ACHA=:date_d, DATE_EXPIRATION=:date_f, SATUTS=:status, "
                  "TYPE=:type, ETAT=:etat WHERE ID_A=:id");

    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":categorie", categorie);
    query.bindValue(":date_d", dateDebut);
    query.bindValue(":date_f", dateFin);
    query.bindValue(":status", statut);
    query.bindValue(":type", type);
    query.bindValue(":etat", etat);

    return query.exec();
}
