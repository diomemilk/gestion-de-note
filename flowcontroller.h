#ifndef FRONTCONTROLLER_H
#define FRONTCONTROLLER_H

#include "uiauthentification.h"
#include "uiadministrateur.h"
#include "service.h"
#include "usermodel.h"
#include "profile.h"
#include "uiresponsable.h"
#include "uifarmateur.h"
#include "mainformateur.h"


class FlowController : public QObject
{
    Q_OBJECT

private:
    //les interfaces graphique
    UiAuthentification* uiAuthentification;
    UIAdministrateur* uiAdministrateur;
    profile* prof;
    UIResponsable* uiresponsable;
    UIFarmateur* uifarmateur;
    MainFormateur* mainFormateur;
    User us;


   //couche service

    Service* service;


private slots:


    /**
     * @brief onAuthentification buttons clicked
     *
     */
    void onAuthentificationLoginClicked();
    void onAuthentificationSignUpClicked();
    void onAuthentificationExitClicked();

    /**
    * @brief onUIAdministrateur buttons clicked
    *
    */
    void onUIAdministrateurValiderClicked();
    void onUIAdministrateurListerClicked();
    void onUIAdministrateurEffacerClicked();
    void onUIAdministrateurSupprimerClicked();
    void onUIAdministrateurExitClicked();
    void onUIAdministrateurRechercherClicked();
    void onUIAdministrateurProfilClicked();
    void onUIAdministrateurRetourClicked();

    /**
    * @brief onUIResponsable buttons clicked
    */

    void onUIResponsableValiderClicked();
    void onUIResponsableListerEtudiantClicked();
    void onUIResponsableListerFormateurClicked();
    void onUIResponsableListerMatiereClicked();
    void onUIResponsableEffacerClicked();
    void onUIResponsableSupprimerClicked();
    void onUIResponsableExitClicked();
    void onUIResponsableRechercherClicked();
    void onUIResponsableProfilClicked();


    void onUIResponsableEnregisterClasseClicked();
    void onUIResponsableEnregisterModuleClicked();
    void onUIResponsableGererFormateurClicked();


    void onFormatuerEnregisterClicked();
    void onFormatuerListerGFClicked();
    void onFormatuerExitClicked();
    void onFormatuerRetourClicked();
    void onFormatuerSupprimerClicked();

    //profile
    void ModifierProfileClicked();
    void ModifierPasswordClicked();

public:
    void exec();




    FlowController();
    ~FlowController();
};

#endif // FLOWTCONTROLLER_H
