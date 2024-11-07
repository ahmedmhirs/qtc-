#ifndef ARTICLE_H
#define ARTICLE_H

#include <QString>
#include <QDate>
#include <QSqlQueryModel>

class Article
{
private:
    QString id;
    QString nom;
    QString categorie;
    int statut;
    QString type;
    QString etat;
    QDate dateDebut;
    QDate dateFin;

public:
    Article();
    Article(const QString& id, const QString& nom, const QString& categorie,
            int statut, const QDate& dateDebut, const QDate& dateFin,
            const QString& type, const QString& etat);

    // Getters
    QString getId() const { return id; }
    QString getNom() const { return nom; }
    QString getCategorie() const { return categorie; }
    int getStatut() const { return statut; }
    QDate getDateDebut() const { return dateDebut; }
    QDate getDateFin() const { return dateFin; }
    QString getType() const { return type; }
    QString getEtat() const { return etat; }

    // Setters
    void setId(const QString& id);
    void setNom(const QString& nom);
    void setCategorie(const QString& categorie);
    void setStatut(int statut);
    void setDateDebut(const QDate& dateDebut);
    void setDateFin(const QDate& dateFin);
    void setType(const QString& type);
    void setEtat(const QString& etat);

    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(const QString& id);
    bool modifier(const QString& id);

private:
    bool isValid() const;
};

#endif // ARTICLE_H
