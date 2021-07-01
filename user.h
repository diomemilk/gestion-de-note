#ifndef USER_H
#define USER_H

#include <QString>

enum TypeUser {
    ADMINISTRATEUR,
    FORMATEUR,
    ETUDIANT,
    RESPONSABLE

};

class User
{
private:
    uint identifiant;
    QString nom;
    QString prenom;
    QString login;
    QString password;
    QString type;
    QString dates_Naiss;
    QString Tel;
    QString Sexe;
    QString Lieu_Nais;
    uint Numero_CNI;
    QString Matricule;

public:
    User();
    User(uint, QString, QString, QString, QString,QString,QString,QString,QString,uint,QString);
    User(QString, QString, QString, QString,QString, QString, QString, QString,uint,QString);

    uint getIdentifiant() { return identifiant; }
    QString getNom() { return nom; }
    QString getPrenom() { return prenom; }
    QString getLogin() { return login; }
    QString getPassword() { return password; }
    QString getType() { return type; }
    QString getDates_Naiss() { return dates_Naiss; }
    QString getTel() { return Tel; }
    QString getSexe() { return Sexe; }
    QString getLieu_Nais() { return Lieu_Nais; }
    uint getNumero_CNI() { return Numero_CNI; }
     QString getMatricule() { return Matricule; }

    void setIdentifiant(uint identifiant) { this->identifiant = identifiant; }
    void setNom(QString nom) { this->nom = nom; }
    void setPrenom(QString prenom) { this->prenom = prenom; }
    void setLogin(QString login) {  this->login = login; }
    void setPassword(QString password) { this->password = password; }
    void setType(QString type) { this->type = type; }
    void setDates_Naiss(QString dates_Naiss) { this->dates_Naiss = dates_Naiss; }
    void setTel(QString Tel) { this->Tel = Tel; }
    void setSexe(QString Sexe) { this->Sexe = Sexe; }
    void setLieu_Nais(QString Lieu_Nais) { this->Lieu_Nais = Lieu_Nais; }
    void setMatricule(QString Matricule) { this->Matricule = Matricule; }
    void setNumero_CNI(uint Numero_CNI) { this->Numero_CNI = Numero_CNI; }


};

#endif // USER_H
