#include "gestionformatuermodel.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlResult>

GestionFormatuerModel::GestionFormatuerModel(DBAccess *dbAccess)
{
    this->dbAccess = dbAccess;

    GestionFormatuerModel::clear();
}

void GestionFormatuerModel::create(GestionFarmateur gf)
{
    dbAccess->open();

    QSqlQuery query(dbAccess->database());
    query.prepare("INSERT INTO G_formateur (Matiere, classe, jour, matricule, heure) "
                              "VALUES (:Matiere, :classe, :jour, :matricule, :heure)");
    query.bindValue(":matricule", gf.getMatricule());
    query.bindValue(":heure", gf.getHeure());
    query.bindValue(":jour", gf.getJour());
    query.bindValue(":classe", gf.getCl());
    query.bindValue(":Matiere", gf.getMatiere());
    query.bindValue(":id", gf.getId());



    query.exec();

    readAll();

    qDebug () << "G_formateur" << gf.getId() << "created successfully!";
    dbAccess->close();
}


void GestionFormatuerModel::update(GestionFarmateur gf)
{
    dbAccess->open();

    QSqlQuery query(dbAccess->database());
    query.prepare("UPDATE G_formateur SET Matiere=:Matiere, classe=:classe, jour=:jour, matricule=:matricule, heure=:heure"
                    "WHERE id=:id");
    query.bindValue(":matricule", gf.getMatricule());
    query.bindValue(":heure", gf.getHeure());
    query.bindValue(":jour", gf.getJour());
    query.bindValue(":Matiere", gf.getMatiere());
    query.bindValue(":classe", gf.getCl());
    query.bindValue(":id", gf.getId());

    query.exec();

    readAll();

    qDebug () << "GestionFormatuer" << gf.getId() << " updated successfully!" ;
    dbAccess->close();
}

void GestionFormatuerModel::remove(uint identifiant)
{
    dbAccess->open();

    QSqlQuery query(dbAccess->database());
    query.prepare("DELETE FROM G_formateur WHERE id=:id");
    query.bindValue(":id", identifiant);
    query.exec();

    readAll();

    qDebug () << "GestionFormatuer with id :" << identifiant << " has been deleted successfully!" ;
    dbAccess->close();
}


QSqlQueryModel* GestionFormatuerModel::readAll()
{
    QSqlQueryModel * model =new QSqlQueryModel();
    dbAccess->open();

    QSqlDatabase database = dbAccess->database();
    model->setQuery("SELECT * FROM G_formateur", database);

    this->setHeaderData(0, Qt::Horizontal, tr("Identifiant"));
    this->setHeaderData(1, Qt::Horizontal, tr("Matiere"));
    this->setHeaderData(2, Qt::Horizontal, tr("Classe"));
    this->setHeaderData(3, Qt::Horizontal, tr("Jour"));
    this->setHeaderData(4, Qt::Horizontal, tr("Heure"));
    this->setHeaderData(5, Qt::Horizontal, tr("Matricule de Formateur"));


    qDebug () << "GestionFormatuerModel displayed successfully!";
    dbAccess->close();
    return model;
}


void GestionFormatuerModel::clear()
{
    dbAccess->open();

    QSqlDatabase database = dbAccess->database();
    this->setQuery("SELECT * FROM G_formateur WHERE id=-1", database);

    this->setHeaderData(0, Qt::Horizontal, tr("Identifiant"));
    this->setHeaderData(1, Qt::Horizontal, tr("Matiere"));
    this->setHeaderData(2, Qt::Horizontal, tr("Classe"));
    this->setHeaderData(3, Qt::Horizontal, tr("Jour"));
    this->setHeaderData(4, Qt::Horizontal, tr("Heure"));
    this->setHeaderData(5, Qt::Horizontal, tr("Matricule de Formateur"));

    dbAccess->close();
}

GestionFormatuerModel::~GestionFormatuerModel()
{
    qDebug() << "GestionFormatuerModel Object has been deleted!";
}
