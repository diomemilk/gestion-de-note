#include "service.h"

// Here we define the static Service pointer
Service* Service::instance = nullptr;

Service::Service()
{
      connection = DBAccess::getInstance()->database().connectionName();
}

Service* Service::getInstance()
{
    if (instance == nullptr) {
       instance = new Service();
    }

    return instance;
}

void Service::release()
{
    if (instance != nullptr) {
       delete instance;
    }
}

bool Service::authentifier(QString login, QString password, User* user)
{
    UserModel userModel(DBAccess::getInstance());


    if (true == userModel.readBy(login, password, user))
    {
        return true;
    }

    return false;
}

Service::~Service()
{
    DBAccess::release();
    QSqlDatabase::removeDatabase(connection);
    qDebug() << "Service Object has been deleted!";
}


void Service::createUser(User user)
{
    UserModel userModel(DBAccess::getInstance());
    userModel.create(user);
}

void Service::createClasse(classe classe)
{
    classemodel classemodel(DBAccess::getInstance());
    classemodel.create(classe);
}

void Service::createModule(Module module)
{
    ModuleModel ModuleModel(DBAccess::getInstance());
    ModuleModel.create(module);
}

void Service::createGf(GestionFarmateur gf)
{
    GestionFormatuerModel GestionFormatuerModel(DBAccess::getInstance());
    GestionFormatuerModel.create(gf);
}

void Service::updateUser(User user)
{
    UserModel userModel(DBAccess::getInstance());
    userModel.update(user);
}

void Service::updateProfileUser(User user)
{
    UserModel userModel(DBAccess::getInstance());
    userModel.updateProfile(user);
}
void Service::ModifierPassword(User user)
{
    UserModel userModel(DBAccess::getInstance());
    userModel.ModifierPassword(user);
}

void Service::updateClasse(classe classe)
{
    classemodel classemodel(DBAccess::getInstance());
    classemodel.update(classe);
}

void Service::updateModule(Module module)
{
    ModuleModel ModuleModel(DBAccess::getInstance());
    ModuleModel.update(module);
}

void Service::updateGf(GestionFarmateur gf)
{
    GestionFormatuerModel GestionFormatuerModel(DBAccess::getInstance());
    GestionFormatuerModel.update(gf);
}


void Service::removeUser(uint identifiant){
    UserModel userModel(DBAccess::getInstance());
    userModel.remove(identifiant);

}

void Service::removeClassse(uint identifiant){
    classemodel classemodel(DBAccess::getInstance());
    classemodel.remove(identifiant);

}

void Service::removeModule(uint identifiant){
    ModuleModel ModuleModel(DBAccess::getInstance());
    ModuleModel.remove(identifiant);

}

void Service::removeGf(uint identifiant){
    GestionFormatuerModel GestionFormatuerModel(DBAccess::getInstance());
    GestionFormatuerModel.remove(identifiant);

}

QSqlQueryModel* Service::listerUser(){
     // QSqlQueryModel * model =new QSqlQueryModel();
    UserModel userModel(DBAccess::getInstance());
   // model = userModel.readAll();
    return userModel.readAll();
}

QSqlQueryModel* Service::listerEtudiant(){
     // QSqlQueryModel * model =new QSqlQueryModel();
    UserModel userModel(DBAccess::getInstance());
   // model = userModel.readAll();
    return userModel.readAllEtudiant();
}

QSqlQueryModel* Service::listerFormateur(){
     // QSqlQueryModel * model =new QSqlQueryModel();
    UserModel userModel(DBAccess::getInstance());
   // model = userModel.readAll();
    return userModel.readAllFormateur();
}


QSqlQueryModel* Service::listerClasse(){

    classemodel cal(DBAccess::getInstance());

    return cal.readAllClasse();
}

QSqlQueryModel* Service::listerMaliere(){

    ModuleModel moduleModel(DBAccess::getInstance());

    return moduleModel.readAll();
}

QSqlQueryModel* Service::listerGf(){

    GestionFormatuerModel GestionFormatuerModel(DBAccess::getInstance());

    return GestionFormatuerModel.readAll();
}


QSqlQueryModel* Service::RechercheUser(QString rech){

    UserModel userModel(DBAccess::getInstance());

    return userModel.readAll(rech);

}

