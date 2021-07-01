#include "user.h"

User::User()
{}

User::User(uint _identifiant, QString _nom, QString _prenom, QString _login, QString _password, QString _date_Nais, QString _Tel, QString _Sexe, QString _Lieu_Nais,uint _Numero_CNI,QString _Matricule):
    identifiant(_identifiant), nom(_nom), prenom(_prenom), login(_login), password(_password), dates_Naiss(_date_Nais), Tel(_Tel), Sexe(_Sexe), Lieu_Nais(_Lieu_Nais), Numero_CNI(_Numero_CNI),Matricule(_Matricule)
{}

User::User(QString _nom, QString _prenom, QString _login, QString _password, QString _date_Nais, QString _Tel, QString _Sexe, QString _Lieu_Nais, uint _Numero_CNI,QString _Matricule):
    nom(_nom), prenom(_prenom), login(_login), password(_password), dates_Naiss(_date_Nais), Tel(_Tel), Sexe(_Sexe), Lieu_Nais(_Lieu_Nais), Numero_CNI(_Numero_CNI),Matricule(_Matricule)
{}
