#include "classemodel.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlResult>

classemodel::classemodel(DBAccess *dbAccess)
{
    this->dbAccess = dbAccess;

    classemodel::clear();
}

void classemodel::create(classe cl)
{
    dbAccess->open();

    QSqlQuery query(dbAccess->database());
    query.prepare("INSERT INTO t_classe (nam, capacite) "
                              "VALUES (:nam, :capacite)");
    query.bindValue(":nam", cl.getNam());
    query.bindValue(":capacite", cl.getCapacite());


    query.exec();

    readAll();

    qDebug () << "classe" << cl.getNam() << "created successfully!";
    dbAccess->close();
}

void classemodel::update(classe cl)
{
    dbAccess->open();

    QSqlQuery query(dbAccess->database());
    query.prepare("UPDATE t_classe SET nam=:nam, capacite=:capacite"
                    "WHERE id=:id");
    query.bindValue(":nam", cl.getNam());
    query.bindValue(":capacite", cl.getCapacite());
    query.bindValue(":id", cl.getId());

    query.exec();

    readAll();

    qDebug () << "Classe" << cl.getNam() << " updated successfully!" ;
    dbAccess->close();
}

void classemodel::remove(uint identifiant)
{
    dbAccess->open();

    QSqlQuery query(dbAccess->database());
    query.prepare("DELETE FROM t_classe WHERE id=:id");
    query.bindValue(":id", identifiant);
    query.exec();

    readAll();

    qDebug () << "Classe with id :" << identifiant << " has been deleted successfully!" ;
    dbAccess->close();
}



QSqlQueryModel* classemodel::readAll()
{
    QSqlQueryModel * model =new QSqlQueryModel();
    dbAccess->open();

    QSqlDatabase database = dbAccess->database();
    model->setQuery("SELECT id, nam, capacite FROM t_classe", database);

    model->setHeaderData(0, Qt::Horizontal, tr("Identifiant"));
    model->setHeaderData(1, Qt::Horizontal, tr("Nam"));
    model->setHeaderData(2, Qt::Horizontal, tr("capacité"));


    qDebug () << "classe displayed successfully!";
    dbAccess->close();
    return model;
}

QSqlQueryModel* classemodel::readAllClasse()
{
    QSqlQueryModel * model =new QSqlQueryModel();
    dbAccess->open();

    QSqlDatabase database = dbAccess->database();
    model->setQuery("SELECT nam FROM t_classe", database);
    qDebug () << "classe displayed successfully!";
    dbAccess->close();
    return model;
}



void classemodel::clear()
{
    dbAccess->open();

    QSqlDatabase database = dbAccess->database();
    this->setQuery("SELECT * FROM t_classe WHERE id=-1", database);

    this->setHeaderData(0, Qt::Horizontal, tr("Identifiant"));
    this->setHeaderData(1, Qt::Horizontal, tr("Nom"));
    this->setHeaderData(2, Qt::Horizontal, tr("capacité"));

    dbAccess->close();
}

classemodel::~classemodel()
{
    qDebug() << "classemodel Object has been deleted!";
}

