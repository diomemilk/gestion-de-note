#include "uiadministrateur.h"
#include "ui_uiadministrateur.h"
#include "QMessageBox"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>

UIAdministrateur::UIAdministrateur(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UIAdministrateur)
{
    ui->setupUi(this);

}
UIAdministrateur::UIAdministrateur(QObject *controller)
    : ui(new Ui::UIAdministrateur)
{
    ui->setupUi(this);
    connect(ui->pushButtonValider, SIGNAL(clicked()), controller, SLOT(onUIAdministrateurValiderClicked()));
    connect(ui->pushButtonLister, SIGNAL(clicked()), controller, SLOT(onUIAdministrateurListerClicked()));
    connect(ui->pushButtonProfil, SIGNAL(clicked()), controller, SLOT(onUIAdministrateurProfilClicked()));
    connect(ui->pushButtonExit, SIGNAL(clicked()), controller, SLOT(onUIAdministrateurExitClicked()));
    connect(ui->pushButtonEffacer, SIGNAL(clicked()), controller, SLOT(onUIAdministrateurEffacerClicked()));
    connect(ui->pushButtonSupprimer, SIGNAL(clicked()), controller, SLOT(onUIAdministrateurSupprimerClicked()));
    connect(ui->pushButtonRechercher, SIGNAL(clicked()), controller, SLOT(onUIAdministrateurRechercherClicked()));


}

UIAdministrateur::~UIAdministrateur()
{
    delete ui;
}

bool UIAdministrateur::getInputs(int* identifiant,QString &nom,QString &prenom, QString &login,QString &password,QString &type, QString &dates_Naiss, QString &Tel, QString &Sexe, QString &Lieu_Nais,  int* CNI,bool* operation,QString &Matricule){

    if(ui->lineEditId->text().compare("") !=0){
        *identifiant = ui->lineEditId->text().toInt();

    }

    login = ui->lineEditLogin->text();

    nom = ui->lineEditUsername->text();

    prenom = ui->lineEditprenome->text();

    password = ui->lineEditPassword->text();

    *CNI =  ui->lineEdit_CNI->text().toInt();

    Tel =  ui->lineEdit_Tel->text();

    Sexe=  ui->comboBoxRole_Sexe->currentText();

    Lieu_Nais =  ui->lineEdit_lieu->text();

    dates_Naiss = ui->dateEdit_Naiss->text()  ;

    Matricule = ui->lineEdit_Matricule->text();

    type = ui->comboBoxRole->currentText();
    *operation = ui->radioButtonCreer->isChecked();//true si creation

    if(password.compare(ui->lineEditConfirmPassword->text()) !=0){
        QMessageBox::critical(this,"Erreur","password et confirmpassword different ",QMessageBox::Ok);
        return false;
    }


    if(login.compare("") == 0 ||  nom.compare("") ==0 || Matricule.compare("") ==0){

        QMessageBox::critical(this,"information","Saisissez votre nom et login, Matricule",QMessageBox::Ok);
        return false;
    }
    return true;
}

bool UIAdministrateur::getId(int *identifiant, QString &login){


     *identifiant = ui->lineEditId->text().toInt();
     login = ui->lineEditLogin->text();
     return true;
}

bool UIAdministrateur::getRech(QString &rech){

    rech = ui->lineEditRechercher->text();
    if(rech.compare("") == 0){


    QMessageBox::critical(this,"information","Input rechercher est vide !",QMessageBox::Ok);
    return false;
    }

     return true;
}


void UIAdministrateur::getTable(QSqlQueryModel* model ){
    ui->tableView->setModel(model);
}
void UIAdministrateur::getTableRech(QSqlQueryModel *model){
    ui->tableView->setModel(model);
}


void UIAdministrateur::effacerInputs(){

    ui->lineEditId->clear();
    ui->lineEditUsername->clear();
    ui->lineEditprenome->clear();
    ui->lineEditLogin->clear();
    ui->lineEditConfirmPassword->clear();
    ui->lineEditPassword->clear();
    ui->lineEdit_Tel->clear();
    ui->lineEdit_lieu->clear();
    ui->lineEdit_CNI->clear();
    ui->lineEdit_Matricule->clear();


}

void UIAdministrateur::setNam(QString login){

    ui->labelUtilisateurConnecte->setText(login);
}


void UIAdministrateur::on_tableView_activated(const QModelIndex &index)
{
      QString val =  ui->tableView->model()->data(index).toString();
      db = QSqlDatabase::addDatabase("QSQLITE");
      db.setDatabaseName("C:/Users/hp/Documents/Projet QT/gestion_Note/gestion_notes.db");
      ui->lineEditUsername->isHidden();

      db.open();
      qDebug() << db.lastError();
      qDebug() << "DBAccess Object created and 'gestion_notes.db' has been added as default database!";
      QSqlQuery query;

      query.exec( "SELECT identifiant, nom, prenom, login, type, date_Naiss, Tel, Sexe, Lieu_Naiss, Numero_CNI FROM t_users WHERE identifiant='"+val+"' or nom='"+val+"' or prenom='"+val+"' or login='"+val+"' or type='"+val+"'"
"or date_Naiss='"+val+"' or Tel='"+val+"' or Sexe='"+val+"' or Lieu_Naiss='"+val+"' or Numero_CNI='"+val+"' ");

      while(query.next()){
             ui->lineEditId->setText(query.value(0).toString());
             ui->lineEditUsername->setText(query.value(1).toString());
             ui->lineEditprenome->setText(query.value(2).toString());
             ui->lineEditLogin->setText(query.value(3).toString());
             ui->comboBoxRole->setCurrentText(query.value(4).toString());
             // ui->dateEdit_Naiss->setText(query.value(5).toString());
             ui->lineEdit_Tel->setText(query.value(6).toString());
             ui->comboBoxRole_Sexe->setCurrentText(query.value(7).toString());
             ui->lineEdit_lieu->setText(query.value(8).toString());
             ui->lineEdit_CNI->setText(query.value(9).toString());
         }
}


void  UIAdministrateur::notificationInfo(QString message){

    QMessageBox::information(this,"information",message);
}

