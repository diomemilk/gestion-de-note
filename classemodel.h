#ifndef CLASSEMODEL_H
#define CLASSEMODEL_H
#include <QSqlQueryModel>

#include "dbaccess.h"
#include <classe.h>

class classemodel: public QSqlQueryModel
{
private:
    DBAccess *dbAccess;
public:
    classemodel(DBAccess *dbAccess);
    ~classemodel();

    void clear();

    // CRUD methods
    void create(classe cl);
    void update(classe cl);
    void remove(uint id);
    QSqlQueryModel* readAll();
    QSqlQueryModel* readAllClasse();
};

#endif // CLASSEMODEL_H
