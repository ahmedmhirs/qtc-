#include "article.h"
#include <QSqlQuery>
#include "article.h"

article::article(int id, const QString& nom, const QString& catégorie, const QDate& datedebut, const QDate& datefin, const QString& statut) {
    this->id = id;
    this->nom = nom;
    this->catégorie = catégorie;
    this->datedebut = datedebut;
    this->datefin = datefin;
    this->statut=statut;
}


bool article::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO ARTICLE (ID_A, NOM_A, CATEGORIE, DATE_ACHA, DATE_EXPIRATION,SATUTS) "
                  "VALUES (:id, :nom, :catégorie, :datedebut, :datefin, :statut)");
    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":catégorie", catégorie);
    query.bindValue(":datedebut", datedebut);
    query.bindValue(":datefin", datefin);
    query.bindValue(":statut", statut);
    if (query.exec()) {
        return true;
    } else {
        qDebug() << "Error inserting product:" << query.lastError().text();
        return false;
    }
}
