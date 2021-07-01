#include "gestionfarmateur.h"

QString GestionFarmateur::getMatricule() const
{
    return matricule;
}

void GestionFarmateur::setMatricule(const QString &value)
{
    matricule = value;
}

QString GestionFarmateur::getMatiere() const
{
    return matiere;
}

void GestionFarmateur::setMatiere(const QString &value)
{
    matiere = value;
}

QString GestionFarmateur::getCl() const
{
    return cl;
}

void GestionFarmateur::setCl(const QString &value)
{
    cl = value;
}

QString GestionFarmateur::getJour() const
{
    return jour;
}

void GestionFarmateur::setJour(const QString &value)
{
    jour = value;
}

QString GestionFarmateur::getHeure() const
{
    return heure;
}

void GestionFarmateur::setHeure(const QString &value)
{
    heure = value;
}

uint GestionFarmateur::getId() const
{
    return id;
}

void GestionFarmateur::setId(const uint &value)
{
    id = value;
}

GestionFarmateur::GestionFarmateur()
{

}
