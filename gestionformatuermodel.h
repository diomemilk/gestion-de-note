#ifndef GESTIONFORMATUERMODEL_H
#define GESTIONFORMATUERMODEL_H
#include <QSqlQueryModel>

#include "dbaccess.h"
#include <gestionfarmateur.h>
class GestionFormatuerModel: public QSqlQueryModel
{
private:
    DBAccess *dbAccess;
public:
    GestionFormatuerModel(DBAccess *dbAccess);
    ~GestionFormatuerModel();
    void clear();

    // CRUD methods
    void create(GestionFarmateur gf);
    void update(GestionFarmateur gf);
    void remove(uint id);
    QSqlQueryModel* readAll();
};

#endif // GESTIONFORMATUERMODEL_H
