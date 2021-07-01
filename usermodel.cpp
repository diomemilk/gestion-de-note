#include "usermodel.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlResult>

UserModel::UserModel(DBAccess *dbAccess)
{
    this->dbAccess = dbAccess;

    UserModel::clear();
}

void UserModel::create(User user)
{
    dbAccess->open();

    QSqlQuery query(dbAccess->database());
    query.prepare("INSERT INTO t_users (nom, prenom, login, password, type, date_Naiss, Tel, Sexe, Lieu_Naiss, Numero_CNI, Matricule) "
                    "VALUES (:nom, :prenom, :login, :password, :type, :date_Naiss, :Tel, :Sexe, :Lieu_Naiss, :Numero_CNI, :Matricule)");
    query.bindValue(":nom", user.getNom());
    query.bindValue(":prenom", user.getPrenom());
    query.bindValue(":login", user.getLogin());
    query.bindValue(":password", user.getPassword());
    query.bindValue(":type", user.getType());
    query.bindValue(":date_Naiss", user.getDates_Naiss());
    query.bindValue(":Tel", user.getTel());
    query.bindValue(":Sexe", user.getSexe());
    query.bindValue(":Lieu_Naiss", user.getLieu_Nais());
    query.bindValue(":Numero_CNI", user.getNumero_CNI());
    query.bindValue(":Matricule", user.getMatricule());

    query.exec();

    readAll();

    qDebug () << "User" << user.getNom() << "created successfully!";
    dbAccess->close();
}

QSqlQueryModel* UserModel::readAll()
{
    QSqlQueryModel * model =new QSqlQueryModel();
    dbAccess->open();

    QSqlDatabase database = dbAccess->database();
    model->setQuery("SELECT identifiant, Matricule, nom, prenom, login, type, date_Naiss, Tel, Sexe, Lieu_Naiss, Numero_CNI FROM t_users", database);

    model->setHeaderData(0, Qt::Horizontal, tr("Identifiant"));
    model->setHeaderData(1, Qt::Horizontal, tr("Matricule"));
    model->setHeaderData(2, Qt::Horizontal, tr("Nom"));
    model->setHeaderData(3, Qt::Horizontal, tr("Prénom"));
    model->setHeaderData(4, Qt::Horizontal, tr("Login"));
    model->setHeaderData(5, Qt::Horizontal, tr("Type"));
    model->setHeaderData(6, Qt::Horizontal, tr("date_Naiss"));
    model->setHeaderData(7, Qt::Horizontal, tr("Tel"));
    model->setHeaderData(8, Qt::Horizontal, tr("Sexe"));
    model->setHeaderData(9, Qt::Horizontal, tr("Lieu_Naiss"));
    model->setHeaderData(10, Qt::Horizontal, tr("Numero_CNI"));


    qDebug () << "Users displayed successfully!";
    dbAccess->close();
    return model;
}

QSqlQueryModel* UserModel::readAll(QString rech)
{
    QSqlQueryModel * model =new QSqlQueryModel();
    dbAccess->open();

    QSqlDatabase database = dbAccess->database();
    model->setQuery("SELECT identifiant, Matricule, nom, prenom, login, type, date_Naiss, Tel, Sexe, Lieu_Naiss, Numero_CNI FROM t_users  WHERE nom='"+rech+"'  ", database);


    model->setHeaderData(0, Qt::Horizontal, tr("Identifiant"));
    model->setHeaderData(1, Qt::Horizontal, tr("Matricule"));
    model->setHeaderData(2, Qt::Horizontal, tr("Nom"));
    model->setHeaderData(3, Qt::Horizontal, tr("Prénom"));
    model->setHeaderData(4, Qt::Horizontal, tr("Login"));
    model->setHeaderData(5, Qt::Horizontal, tr("Type"));
    model->setHeaderData(6, Qt::Horizontal, tr("date_Naiss"));
    model->setHeaderData(7, Qt::Horizontal, tr("Tel"));
    model->setHeaderData(8, Qt::Horizontal, tr("Sexe"));
    model->setHeaderData(9, Qt::Horizontal, tr("Lieu_Naiss"));
    model->setHeaderData(10, Qt::Horizontal, tr("Numero_CNI"));

    qDebug () << "Users displayed successfully!";
    dbAccess->close();
    return model;
}

QSqlQueryModel* UserModel::readAll(uint Id)
{
    QSqlQueryModel * model =new QSqlQueryModel();
    dbAccess->open();

    QSqlDatabase database = dbAccess->database();
    model->setQuery("SELECT identifiant, Matricule, nom, prenom, login, type, date_Naiss, Tel, Sexe, Lieu_Naiss, Numero_CNI FROM t_users WHEHE id=Id ", database);


    model->setHeaderData(0, Qt::Horizontal, tr("Identifiant"));
    model->setHeaderData(1, Qt::Horizontal, tr("Matricule"));
    model->setHeaderData(2, Qt::Horizontal, tr("Nom"));
    model->setHeaderData(3, Qt::Horizontal, tr("Prénom"));
    model->setHeaderData(4, Qt::Horizontal, tr("Login"));
    model->setHeaderData(5, Qt::Horizontal, tr("Type"));
    model->setHeaderData(6, Qt::Horizontal, tr("date_Naiss"));
    model->setHeaderData(7, Qt::Horizontal, tr("Tel"));
    model->setHeaderData(8, Qt::Horizontal, tr("Sexe"));
    model->setHeaderData(9, Qt::Horizontal, tr("Lieu_Naiss"));
    model->setHeaderData(10, Qt::Horizontal, tr("Numero_CNI"));

    qDebug () << "Users displayed successfully!";
    dbAccess->close();
    return model;
}

QSqlQueryModel* UserModel::readAllEtudiant()
{

    QSqlQueryModel * model =new QSqlQueryModel();
    dbAccess->open();

    QSqlDatabase database = dbAccess->database();
    model->setQuery("SELECT identifiant, Matricule, nom, prenom, login, type, date_Naiss, Tel, Sexe, Lieu_Naiss, Numero_CNI FROM t_users WHERE type='ETUDIANT'", database);

    model->setHeaderData(0, Qt::Horizontal, tr("Identifiant"));
    model->setHeaderData(1, Qt::Horizontal, tr("Matricule"));
    model->setHeaderData(2, Qt::Horizontal, tr("Nom"));
    model->setHeaderData(3, Qt::Horizontal, tr("Prénom"));
    model->setHeaderData(4, Qt::Horizontal, tr("Login"));
    model->setHeaderData(5, Qt::Horizontal, tr("Type"));
    model->setHeaderData(6, Qt::Horizontal, tr("date_Naiss"));
    model->setHeaderData(7, Qt::Horizontal, tr("Tel"));
    model->setHeaderData(8, Qt::Horizontal, tr("Sexe"));
    model->setHeaderData(9, Qt::Horizontal, tr("Lieu_Naiss"));
    model->setHeaderData(10, Qt::Horizontal, tr("Numero_CNI"));

    qDebug () << "Users displayed successfully!";
    dbAccess->close();
    return model;
}

QSqlQueryModel* UserModel::readAllFormateur()
{

    QSqlQueryModel * model =new QSqlQueryModel();
    dbAccess->open();

    QSqlDatabase database = dbAccess->database();
    model->setQuery("SELECT identifiant, Matricule, nom, prenom, login, type, date_Naiss, Tel, Sexe, Lieu_Naiss, Numero_CNI FROM t_users WHERE type='FORMATEUR'", database);

    model->setHeaderData(0, Qt::Horizontal, tr("Identifiant"));
    model->setHeaderData(1, Qt::Horizontal, tr("Matricule"));
    model->setHeaderData(2, Qt::Horizontal, tr("Nom"));
    model->setHeaderData(3, Qt::Horizontal, tr("Prénom"));
    model->setHeaderData(4, Qt::Horizontal, tr("Login"));
    model->setHeaderData(5, Qt::Horizontal, tr("Type"));
    model->setHeaderData(6, Qt::Horizontal, tr("date_Naiss"));
    model->setHeaderData(7, Qt::Horizontal, tr("Tel"));
    model->setHeaderData(8, Qt::Horizontal, tr("Sexe"));
    model->setHeaderData(9, Qt::Horizontal, tr("Lieu_Naiss"));
    model->setHeaderData(10, Qt::Horizontal, tr("Numero_CNI"));
    qDebug () << "Users displayed successfully!";
    dbAccess->close();
    return model;
}
void UserModel::update(User user)
{
    dbAccess->open();

    QSqlQuery query(dbAccess->database());
    query.prepare("UPDATE t_users SET nom=:nom, prenom=:prenom, login=:login, type=:type, date_Naiss=:date_Naiss, Tel=:Tel, Sexe=:Sexe, Lieu_Naiss=:Lieu_Naiss, Numero_CNI=:Numero_CNI, Matricule=:Matricule "
                    "WHERE identifiant=:identifiant");
    query.bindValue(":nom", user.getNom());
    query.bindValue(":prenom", user.getPrenom());
    query.bindValue(":login", user.getLogin());
    //query.bindValue(":password", user.getPassword());
    query.bindValue(":type", user.getType());
    query.bindValue(":identifiant", user.getIdentifiant());
    query.bindValue(":date_Naiss", user.getDates_Naiss());
    query.bindValue(":Tel", user.getTel());
    query.bindValue(":Sexe", user.getSexe());
    query.bindValue(":Lieu_Naiss", user.getLieu_Nais());
    query.bindValue(":Numero_CNI", user.getNumero_CNI());
    query.bindValue(":Matricule", user.getMatricule());
    query.exec();

    readAll();

    qDebug () << "User" << user.getNom() << " updated successfully!" ;
    dbAccess->close();
}

void UserModel::updateProfile(User user)
{
    dbAccess->open();

    QSqlQuery query(dbAccess->database());
    query.prepare("UPDATE t_users SET nom=:nom, prenom=:prenom, login=:login, Tel=:Tel "
                    "WHERE identifiant=:identifiant");
    query.bindValue(":nom", user.getNom());
    query.bindValue(":prenom", user.getPrenom());
    query.bindValue(":login", user.getLogin());
    query.bindValue(":identifiant", user.getIdentifiant());
    query.bindValue(":Tel", user.getTel());


    query.exec();

    readAll();

    qDebug () << "User" << user.getNom() << " updated successfully!" ;
    dbAccess->close();
}

void  UserModel::ModifierPassword(User user){
    dbAccess->open();

    QSqlQuery query(dbAccess->database());
    query.prepare("UPDATE t_users SET password=:password "
                    "WHERE identifiant=:identifiant");
    query.bindValue(":identifiant", user.getIdentifiant());
    query.bindValue(":password", user.getPassword());


    query.exec();

    readAll();

    qDebug () << "User" << user.getNom() << " updated successfully!" ;
    dbAccess->close();


}


void UserModel::remove(uint identifiant)
{
    dbAccess->open();

    QSqlQuery query(dbAccess->database());
    query.prepare("DELETE FROM t_users WHERE identifiant=:identifiant");
    query.bindValue(":identifiant", identifiant);
    query.exec();

    readAll();

    qDebug () << "User with id :" << identifiant << " has been deleted successfully!" ;
    dbAccess->close();
}

bool UserModel::readBy(QString login)
{
    dbAccess->open();

    QSqlQuery query(dbAccess->database());
    query.prepare("SELECT identifiant AS Identifiant, nom AS Nom, prenom AS Prénom, login AS Login, type AS Type FROM t_users WHERE login=:login");
    query.bindValue(":login", login);
    query.exec();

    if (false == query.next()) // Aucun enregistrement trouvé
    {
        return false;
    }

   // QSqlRecord record = query.record();
    this->setQuery(query);

    qDebug() << "User with login" << login << "found.";
    dbAccess->close();

    return true;
}

bool UserModel::readBy(QString login, QString password, User *user)
{
    dbAccess->open();

    QSqlQuery query(dbAccess->database());
    query.prepare("SELECT identifiant, nom, prenom, login, type, date_Naiss, Tel, Sexe, Lieu_Naiss, Numero_CNI, Matricule FROM t_users WHERE login=:login AND password=:password");
    query.bindValue(":login", login);
    query.bindValue(":password", password);
    query.exec();

    if (false == query.next()) // Aucun enregistrement trouvé
    {
        return false;
    }

    QSqlRecord record = query.record();
    user->setLogin(login);
    user->setPassword(password);
    user->setNom(query.value(record.indexOf("nom")).toString());
    user->setPrenom(query.value(record.indexOf("prenom")).toString());
    user->setType(query.value(record.indexOf("type")).toString());
    user->setIdentifiant(query.value(record.indexOf("identifiant")).toUInt());
    user->setTel(query.value(record.indexOf("Tel")).toString());


    qDebug() << "User with name" << user->getNom() << user->getPrenom() << "found.";
    dbAccess->close();

    return true;
}

void UserModel::clear()
{
    dbAccess->open();

    QSqlDatabase database = dbAccess->database();
    this->setQuery("SELECT identifiant, nom, prenom, login, type FROM t_users WHERE identifiant=-1", database);

    this->setHeaderData(0, Qt::Horizontal, tr("Identifiant"));
    this->setHeaderData(1, Qt::Horizontal, tr("Nom"));
    this->setHeaderData(2, Qt::Horizontal, tr("Prénom"));
    this->setHeaderData(3, Qt::Horizontal, tr("Login"));
    this->setHeaderData(4, Qt::Horizontal, tr("Type"));

    dbAccess->close();
}

UserModel::~UserModel()
{
    qDebug() << "UserModel Object has been deleted!";
}









