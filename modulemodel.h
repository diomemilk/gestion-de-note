#ifndef MODULEMODEL_H
#define MODULEMODEL_H
#define CLASSEMODEL_H
#include <QSqlQueryModel>

#include "dbaccess.h"
#include <module.h>

class ModuleModel: public QSqlQueryModel
{
private:
    DBAccess *dbAccess;
public:
    ModuleModel( DBAccess *dbAccess);
    ~ModuleModel();
    void clear();

    // CRUD methods
    void create(Module module);
    void update(Module module);
    void remove(uint id);
    QSqlQueryModel* readAll();
};

#endif // MODULEMODEL_H
