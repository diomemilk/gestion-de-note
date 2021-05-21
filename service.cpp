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

void Service::updateUser(User user)
{
    UserModel userModel(DBAccess::getInstance());
    userModel.update(user);
}

void Service::removeUser(uint identifiant){
    UserModel userModel(DBAccess::getInstance());
    userModel.remove(identifiant);

}

QSqlQueryModel* Service::listerUser(){
     // QSqlQueryModel * model =new QSqlQueryModel();
    UserModel userModel(DBAccess::getInstance());
   // model = userModel.readAll();
    return userModel.readAll();
}






