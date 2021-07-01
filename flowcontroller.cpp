#include "flowcontroller.h"

#include "QMessageBox"
#include <QDebug>
#include "QDateTime"
FlowController::FlowController() : uiAuthentification(nullptr), uiAdministrateur (nullptr), prof(nullptr), uiresponsable(nullptr), uifarmateur(nullptr),mainFormateur(nullptr)
{

     service = Service::getInstance();

}



/**
 * @brief onAuthentification buttons clicked
 *
 */
void FlowController::onAuthentificationLoginClicked(){


    QString login ;
    QString password ;


    if (true == uiAuthentification->getInputs(login, password))
    {
         // User user;

        if (true == service->authentifier(login, password, &us))
        {     // us = user;
              this->uiAuthentification->close();
               delete uiAuthentification;
              uiAuthentification = nullptr;

            if (us.getType().compare("ADMINISTRATEUR") == 0)
            {
                uiAdministrateur = new UIAdministrateur(this);
                uiAdministrateur->setNam(us.getLogin());
                uiAdministrateur->show();

            }
            else if(us.getType().compare("RESPONSABLE") == 0)
            {
             //on affiche la fenetre RESPONSABLE
                uiresponsable = new UIResponsable(this);
                uiresponsable->setNam(us.getLogin());
                uiresponsable->show();
            }
            else if(us.getType().compare("ETUDIANT") == 0)
            {
             //on affiche la fenetre ETUDIANT

            }
            else if(us.getType().compare("FORMATEUR") == 0)
            {
             //on affiche la fenetre FORMATEUR
                uifarmateur = new UIFarmateur(this);
                uifarmateur->show();
            }


        }
        else{
           // QMessageBox::information(uiAuthentification,"information","login ou password incorrect");
           QMessageBox::warning(uiAuthentification, "Error","Incorrect Login/Password, please try again !", QMessageBox::Ok);
        }


    }





}
void FlowController::onAuthentificationSignUpClicked(){

}
void FlowController::onAuthentificationExitClicked(){
    bool bCloseWindow(false);

        if(QMessageBox::Yes == QMessageBox::question(uiAuthentification,"Exit", "quitter l’application? . Exit anyway ?",QMessageBox::Yes,QMessageBox::Cancel)){

            bCloseWindow = true;
        }
        if(bCloseWindow){
           this->uiAuthentification->close();
        }


}


/**
* @brief onUIAdministrateur buttons clicked
*
*/
void FlowController::onUIAdministrateurValiderClicked(){
    int identifiant = -1;
    QString login;
    QString nom;
    QString prenom;
    QString password;
    QString type;
    QString dates_Naiss;
    QString Tel;
    QString Sexe;
    QString Lieu_Nais;
    QString Marticule;
    int Numero_CNI;
    bool operation;
    bool statut = this->uiAdministrateur->getInputs(&identifiant,nom,prenom, login,password,type,dates_Naiss,Tel,Sexe,Lieu_Nais,&Numero_CNI,&operation,Marticule);
    if(statut){
        if(operation == true){
            User user ;
            user.setIdentifiant(identifiant);
            user.setNom(nom);
            user.setPrenom(prenom);
            user.setLogin(login);
            user.setPassword(password);
            user.setType(type);
            user.setDates_Naiss(dates_Naiss);
            user.setLieu_Nais(Lieu_Nais);
            user.setNumero_CNI(Numero_CNI);
            user.setSexe(Sexe);
            user.setTel(Tel);
            user.setMatricule(Marticule);

            QString info{ "User "};
            QString info1{ " created successfully!"};
            QString s =  info + nom + info1;
            service->createUser(user);
            this->uiAdministrateur->notificationInfo(s);


        }else {
            User user ;
            user.setIdentifiant(identifiant);
            user.setNom(nom);
            user.setPrenom(prenom);
            user.setLogin(login);
            user.setPassword(password);
            user.setType(type);
            user.setDates_Naiss(dates_Naiss);
            user.setLieu_Nais(Lieu_Nais);
            user.setNumero_CNI(Numero_CNI);
            user.setSexe(Sexe);
            user.setTel(Tel);
            user.setMatricule(Marticule);
            QString info{ "User "};
            QString info1{ " updated successfully!"};
            QString s =  info + nom + info1;
            service->updateUser(user);
            this->uiAdministrateur->notificationInfo(s);

        }
    }

}
void FlowController::onUIAdministrateurListerClicked(){

    this->uiAdministrateur->getTable(service->listerUser());


}
void FlowController::onUIAdministrateurEffacerClicked(){
    this->uiAdministrateur->effacerInputs();

}
void FlowController::onUIAdministrateurSupprimerClicked(){
    int identifiant = -1;
    QString login;
    bool statut = this->uiAdministrateur->getId(&identifiant,login);
    if(statut){

        if(login.compare("")==0){
         this->uiAdministrateur->notificationInfo("selectionner le User qui tu vas supprimer !");

        }
        else{
            bool bCloseWindow(false);
            QString info{ "User with login :"};
            QString info1{ " has been deleted successfully!"};
            QString s =  info + login + info1;

                if(QMessageBox::Yes == QMessageBox::question(uiAuthentification,"Exit", s,QMessageBox::Yes,QMessageBox::Cancel)){

                    bCloseWindow = true;
                }
                if(bCloseWindow){
                    service->removeUser(identifiant);
                    this->uiAdministrateur->notificationInfo(s);
                    this->uiAdministrateur->effacerInputs();
                }
        }
    }
}
void FlowController::onUIAdministrateurExitClicked(){
    bool bCloseWindow(false);

        if(QMessageBox::Yes == QMessageBox::question(uiAdministrateur,"Exit", "quitter l’application? . Exit anyway ?",QMessageBox::Yes,QMessageBox::Cancel)){

            bCloseWindow = true;
        }
        if(bCloseWindow){
           this->uiAdministrateur->close();
        }

}
void FlowController::onUIAdministrateurRechercherClicked(){
    QString rech;
   bool statut = this->uiAdministrateur->getRech(rech);
   if(statut){
     this->uiAdministrateur->getTableRech(service->RechercheUser(rech));
    }

}
void FlowController::onUIAdministrateurProfilClicked(){

    this->uiAdministrateur->hide();

    prof = new profile(this);
    prof->getUser(us);
    prof->show();


}

void FlowController::onUIAdministrateurRetourClicked(){
    this->prof->hide();
    if (us.getType().compare("ADMINISTRATEUR") == 0)
    {
        uiAdministrateur = new UIAdministrateur(this);
        uiAdministrateur->setNam(us.getLogin());
        uiAdministrateur->show();

    }
    else if(us.getType().compare("RESPONSABLE") == 0)
    {
     //on affiche la fenetre RESPONSABLE
        uiresponsable = new UIResponsable(this);
        uiresponsable->setNam(us.getLogin());
        uiresponsable->show();
    }
    else if(us.getType().compare("ETUDIANT") == 0)
    {
     //on affiche la fenetre ETUDIANT

    }
    else if(us.getType().compare("FORMATEUR") == 0)
    {
     //on affiche la fenetre FORMATEUR
        uifarmateur = new UIFarmateur(this);
        uifarmateur->show();
    }


}




/**
* @brief onUIResponsable buttons clicked
*/

void FlowController::onUIResponsableValiderClicked(){
    int identifiant = -1;
    QString login;
    QString nom;
    QString prenom;
    QString password;
    QString type;
    QString dates_Naiss;
    QString Tel;
    QString Sexe;
    QString Lieu_Nais;
    int Numero_CNI;
     QString Marticule;
    bool operation;
    bool statut = this->uiresponsable->getInputs(&identifiant,nom,prenom, login,password,type,dates_Naiss,Tel,Sexe,Lieu_Nais,&Numero_CNI,&operation,Marticule);
    if(statut){
        if(operation == true){
            User user ;
            user.setIdentifiant(identifiant);
            user.setNom(nom);
            user.setPrenom(prenom);
            user.setLogin(login);
            user.setPassword(password);
            user.setType(type);
            user.setDates_Naiss(dates_Naiss);
            user.setLieu_Nais(Lieu_Nais);
            user.setNumero_CNI(Numero_CNI);
            user.setSexe(Sexe);
            user.setTel(Tel);
            user.setMatricule(Marticule);

            QString info{ "User "};
            QString info1{ " created successfully!"};
            QString s =  info + nom + info1;
            service->createUser(user);
            this->uiresponsable->notificationInfo(s);


        }else {
            User user ;
            user.setIdentifiant(identifiant);
            user.setNom(nom);
            user.setPrenom(prenom);
            user.setLogin(login);
            user.setPassword(password);
            user.setType(type);
            user.setDates_Naiss(dates_Naiss);
            user.setLieu_Nais(Lieu_Nais);
            user.setNumero_CNI(Numero_CNI);
            user.setSexe(Sexe);
            user.setTel(Tel);
            user.setMatricule(Marticule);
            QString info{ "User "};
            QString info1{ " updated successfully!"};
            QString s =  info + nom + info1;
            service->updateUser(user);
            this->uiresponsable->notificationInfo(s);

        }
    }

}
void FlowController::onUIResponsableListerEtudiantClicked(){


    this->uiresponsable->getTableEtudiant(service->listerEtudiant());
    this->uiresponsable->getTableclasse(service->listerClasse());

}
void FlowController::onUIResponsableListerFormateurClicked(){
     this->uiresponsable->getTableFormatuer(service->listerFormateur());
     this->uiresponsable->getTableclasse(service->listerClasse());
}
void FlowController::onUIResponsableListerMatiereClicked(){

     this->uiresponsable->getTableFormatuer(service->listerMaliere());
}
void FlowController::onUIResponsableEffacerClicked(){
      this->uiresponsable->effacerInputs();
}
void FlowController::onUIResponsableSupprimerClicked(){}
void FlowController::onUIResponsableExitClicked(){
    bool bCloseWindow(false);

        if(QMessageBox::Yes == QMessageBox::question(uiresponsable,"Exit", "quitter l’application? . Exit anyway ?",QMessageBox::Yes,QMessageBox::Cancel)){

            bCloseWindow = true;
        }
        if(bCloseWindow){
           this->uiresponsable->close();
        }
}
void FlowController::onUIResponsableRechercherClicked(){
    QString rech;
   bool statut = this->uiresponsable->getRech(rech);
   if(statut){
     this->uiresponsable->getTableRech(service->RechercheUser(rech));
    }
}
void FlowController::onUIResponsableProfilClicked(){
   this->uiresponsable->hide();
    prof = new profile(this);
    prof->getUser(us);
    prof->show();

}
void FlowController::onUIResponsableEnregisterClasseClicked(){
    int identifiant = -1;
    QString nam;
    int capacite;
    bool statut = this->uiresponsable->getInputsClasse(&identifiant,nam,&capacite);
    if(statut){
        classe cl;
        cl.setId(identifiant);
        cl.setNam(nam);
        cl.setCapacite(capacite);
        QString info{ "Classe "};
        QString info1{ " created successfully!"};
        QString s =  info + nam + info1;
        service->createClasse(cl);
        this->uiresponsable->notificationInfo(s);

    }
}
void FlowController::onUIResponsableEnregisterModuleClicked(){

    int identifiant = -1;
    QString name_module;
    QString matiere;
    QString classe;

    bool statut = this->uiresponsable->getInputsModule(&identifiant,name_module,matiere,classe);
    if(statut){
        Module module;
        module.setId(identifiant);
        module.setMatiere(matiere);
        module.setName_module(name_module);
        module.setClasse(classe);
        QString info{ "Classe "};
        QString info1{ " created successfully!"};
        QString s =  info + name_module + info1;
        service->createModule(module);
        this->uiresponsable->notificationInfo(s);

    }

}
void FlowController::onUIResponsableGererFormateurClicked(){

    this->uiresponsable->hide();

    mainFormateur = new MainFormateur(this);

    mainFormateur->show();


}
void FlowController::onFormatuerEnregisterClicked(){

    int identifiant = -1;
    QString matricule;
    QString matiere;
    QString classe;
    QString jour;
    QString heure;
     bool operation;

    bool statut = this->mainFormateur->getInputsGf(&identifiant,matiere,classe,jour,heure,matricule,&operation);
    if(statut){
        if(operation == true){
        GestionFarmateur gf;
        gf.setId(identifiant);
        gf.setMatiere(matiere);
        gf.setMatricule(matricule);
        gf.setCl(classe);
        gf.setHeure(heure);
        gf.setJour(jour);

        QString info1{ " created successfully!"};
        QString s =   info1;
        service->createGf(gf);
        this->mainFormateur->notificationInfo(s);
        }else{

            GestionFarmateur gf;
            gf.setId(identifiant);
            gf.setMatiere(matiere);
            gf.setMatricule(matricule);
            gf.setCl(classe);
            gf.setHeure(heure);
            gf.setJour(jour);

            QString info1{ " updated successfully!"};
            QString s =   info1;
            service->updateGf(gf);
            this->mainFormateur->notificationInfo(s);

        }

    }


}
void FlowController::onFormatuerListerGFClicked(){

    this->mainFormateur->getTable(service->listerGf());
     this->mainFormateur->getTableclasse(service->listerClasse());

}
void FlowController::onFormatuerExitClicked(){
    bool bCloseWindow(false);

        if(QMessageBox::Yes == QMessageBox::question(mainFormateur,"Exit", "quitter l’application? . Exit anyway ?",QMessageBox::Yes,QMessageBox::Cancel)){

            bCloseWindow = true;
        }
        if(bCloseWindow){
           this->mainFormateur->close();
        }
}
void FlowController::onFormatuerRetourClicked(){
    this->mainFormateur->hide();
    uiresponsable = new UIResponsable(this);
    uiresponsable->setNam(us.getLogin());
    uiresponsable->show();
}
void FlowController::onFormatuerSupprimerClicked(){


}
void FlowController::exec()
{
    uiAuthentification = new UiAuthentification(this);

    uiAuthentification->show();
}


void FlowController::ModifierProfileClicked(){
    int identifiant = -1;
    QString login;
    QString nom;
    QString prenom;
    QString Tel;
    bool statut = this->prof->getInputs(&identifiant,nom,prenom, login,Tel);
    if(statut){

        User user ;
        user.setIdentifiant(identifiant);
        user.setNom(nom);
        user.setPrenom(prenom);
        user.setLogin(login);
        user.setTel(Tel);
        QString info{ "User "};
        QString info1{ " updated successfully!"};
        QString s =  info + nom + info1;
        service->updateProfileUser(user);
        this->prof->notificationInfo(s);

    }else{
        QString info{ "User "};
        QString info1{ " is not updated  successfully!"};
        QString s =  info + nom + info1;

        this->prof->notificationInfo(s);
    }
}

void FlowController::ModifierPasswordClicked(){
      QString password;
      QString niveauxPassword;
      QString comfriPassword;
      bool statut = this->prof->getIputPassword(password, niveauxPassword, comfriPassword);
      if(statut){

         User user ;
         if(password.compare(us.getPassword()) == 0 || niveauxPassword.compare(comfriPassword) == 0){
             QString ss = "Password is not correct or niveauxPassword and comfriPassword is different";
            this->prof->notificationInfo(ss);
             statut = false;
         }
         if(statut){
         user.setPassword(niveauxPassword);
         QString s =  "updated successfully!";
         service->ModifierPassword(user);
         this->prof->notificationInfo(s);
        }
     }
}
FlowController::~FlowController()
{
    if (uiAuthentification != nullptr)
    {
        delete uiAuthentification;
    }

    if (uiAdministrateur != nullptr)
    {
        delete uiAdministrateur;
    }

    if (service != nullptr)
    {
        Service::release();
    }




}




























