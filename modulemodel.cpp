#include "modulemodel.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlResult>

ModuleModel::ModuleModel(DBAccess *dbAccess)
{
    this->dbAccess = dbAccess;

    ModuleModel::clear();
}

void ModuleModel::create(Module module)
{
    dbAccess->open();

    QSqlQuery query(dbAccess->database());
    query.prepare("INSERT INTO t_module (name_module, matiere,classe) "
                              "VALUES (:name_module, :matiere, :classe)");
    query.bindValue(":name_module", module.getName_module());
    query.bindValue(":matiere", module.getMatiere());
    query.bindValue(":classe", module.getClasse());


    query.exec();

    readAll();

    qDebug () << "Module" << module.getName_module() << "created successfully!";
    dbAccess->close();
}

void ModuleModel::update(Module module)
{
    dbAccess->open();

    QSqlQuery query(dbAccess->database());
    query.prepare("UPDATE t_module SET name_module=:name_module, matiere=:matiere, classe=:classe"
                    "WHERE id=:id");
    query.bindValue(":name_module", module.getName_module());
    query.bindValue(":matiere", module.getMatiere());
    query.bindValue(":classe", module.getClasse());
    query.bindValue(":id", module.getId());

    query.exec();

    readAll();

    qDebug () << "Module" << module.getName_module() << " updated successfully!" ;
    dbAccess->close();
}

void ModuleModel::remove(uint identifiant)
{
    dbAccess->open();

    QSqlQuery query(dbAccess->database());
    query.prepare("DELETE FROM t_module WHERE id=:id");
    query.bindValue(":id", identifiant);
    query.exec();

    readAll();

    qDebug () << "Module with id :" << identifiant << " has been deleted successfully!" ;
    dbAccess->close();
}



QSqlQueryModel* ModuleModel::readAll()
{
    QSqlQueryModel * model =new QSqlQueryModel();
    dbAccess->open();

    QSqlDatabase database = dbAccess->database();
    model->setQuery("SELECT id,matiere,name_module,classe FROM t_module", database);

    model->setHeaderData(0, Qt::Horizontal, tr("Identifiant"));
    model->setHeaderData(1, Qt::Horizontal, tr("Matiere"));
    model->setHeaderData(2, Qt::Horizontal, tr("Name Module"));
    model->setHeaderData(3, Qt::Horizontal, tr("Classe"));


    qDebug () << "Module displayed successfully!";
    dbAccess->close();
    return model;
}



void ModuleModel::clear()
{
    dbAccess->open();

    QSqlDatabase database = dbAccess->database();
    this->setQuery("SELECT * FROM t_classe WHERE id=-1", database);

    this->setHeaderData(0, Qt::Horizontal, tr("Identifiant"));
    this->setHeaderData(1, Qt::Horizontal, tr("Nom"));
    this->setHeaderData(2, Qt::Horizontal, tr("capacité"));

    dbAccess->close();
}

ModuleModel::~ModuleModel()
{
    qDebug() << "ModuleModel Object has been deleted!";
}

