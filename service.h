#ifndef SERVICE_H
#define SERVICE_H
#include "user.h"
#include "usermodel.h"
#include "classe.h"
#include "classemodel.h"
#include "module.h"
#include "modulemodel.h"
#include "gestionfarmateur.h"
#include "gestionformatuermodel.h"
#include <QDebug>
#include <QMessageBox>

class Service
{
private:
    static Service* instance; // The single instance
     QString connection;
    Service();
    ~Service();

public:
    // How to get the single instance of Service
    static Service* getInstance();

    // How the release the single instance of DBAccess
    static void release();

    // Method pour User
    bool authentifier(QString login, QString password, User* user);
    void createUser(User user);
    void updateUser(User user);
    void updateProfileUser(User user);
    void ModifierPassword(User user);
    void removeUser(uint identifiant);
     QSqlQueryModel* listerUser();
     QSqlQueryModel* listerEtudiant();
     QSqlQueryModel* listerFormateur();
     QSqlQueryModel* RechercheUser(QString rech);

     // Method pour classe
     void createClasse(classe cl);
     void updateClasse(classe cl);
     void removeClassse(uint identifiant);
      QSqlQueryModel* listerClasse();

     // Method pour classe
     void createModule(Module module);
     void updateModule(Module module);
     void removeModule(uint identifiant);
     QSqlQueryModel* listerMaliere();

     // Method pour GestionFormateeur
     void createGf(GestionFarmateur gf);
     void updateGf(GestionFarmateur gf);
     void removeGf(uint identifiant);
     QSqlQueryModel* listerGf();



};

#endif // SERVICE_H
