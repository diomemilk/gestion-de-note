#ifndef GESTIONFARMATEUR_H
#define GESTIONFARMATEUR_H
#include <QString>


class GestionFarmateur
{

private:
    uint id;
    QString matricule;
    QString  matiere;
    QString cl;
    QString jour;
    QString heure;
public:
    GestionFarmateur();
    GestionFarmateur(uint,QString,QString,QString,QString,QString);
    QString getMatricule() const;
    void setMatricule(const QString &value);
    QString getMatiere() const;
    void setMatiere(const QString &value);
    QString getCl() const;
    void setCl(const QString &value);
    QString getJour() const;
    void setJour(const QString &value);
    QString getHeure() const;
    void setHeure(const QString &value);
    uint getId() const;
    void setId(const uint &value);
};

#endif // GESTIONFARMATEUR_H
