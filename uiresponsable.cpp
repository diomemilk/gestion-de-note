#include "uiresponsable.h"
#include "ui_uiresponsable.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include "QMessageBox"


UIResponsable::UIResponsable(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UIResponsable)
{
    ui->setupUi(this);
}

UIResponsable::UIResponsable(QObject *controller)
    : ui(new Ui::UIResponsable)
{
    ui->setupUi(this);
    connect(ui->pushButton_valider, SIGNAL(clicked()), controller, SLOT(onUIResponsableValiderClicked()));
    connect(ui->pushButton_Etudiant, SIGNAL(clicked()), controller, SLOT(onUIResponsableListerEtudiantClicked()));
    connect(ui->pushButtonExit, SIGNAL(clicked()), controller, SLOT(onUIResponsableExitClicked()));
    connect(ui->pushButton_Formateur, SIGNAL(clicked()), controller, SLOT(onUIResponsableListerFormateurClicked()));

    connect(ui->pushButton_Matiere, SIGNAL(clicked()), controller, SLOT(onUIResponsableListerMatiereClicked()));
    connect(ui->pushButton_Classe, SIGNAL(clicked()), controller, SLOT(onUIResponsableEnregisterClasseClicked()));
    connect(ui->pushButton_Module, SIGNAL(clicked()), controller, SLOT(onUIResponsableEnregisterModuleClicked()));


    connect(ui->pushButton_gerer, SIGNAL(clicked()), controller, SLOT(onUIResponsableGererFormateurClicked()));
    connect(ui->pushButtonEffacer, SIGNAL(clicked()), controller, SLOT(onUIResponsableEffacerClicked()));
    connect(ui->pushButtonRechercher, SIGNAL(clicked()), controller, SLOT(onUIResponsableRechercherClicked()));
    connect(ui->pushButtonProfil, SIGNAL(clicked()), controller, SLOT(onUIResponsableProfilClicked()));


}


UIResponsable::~UIResponsable()
{
    delete ui;
}

void UIResponsable::getTableEtudiant(QSqlQueryModel* model ){

     ui->tableView->setModel(model);

}

void UIResponsable::getTableFormatuer(QSqlQueryModel *model){

     ui->tableView->setModel(model);

}
void UIResponsable::getTableclasse(QSqlQueryModel *model){

     ui->comboBox_classe->setModel(model);

}
void UIResponsable::getTableRech(QSqlQueryModel *model){

     ui->tableView->setModel(model);

}

bool UIResponsable::getInputs(int* identifiant,QString &nom,QString &prenom, QString &login,QString &password,QString &type, QString &dates_Naiss, QString &Tel, QString &Sexe, QString &Lieu_Nais,  int* CNI,bool* operation,QString &Matricule){

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

    dates_Naiss = ui->dateEdit_Naiss->text();

    Matricule = ui->lineEdit_Matricule->text();


    type = ui->comboBoxRole->currentText();
    *operation = ui->radioButtonCreer->isChecked();//true si creation

    if(password.compare(ui->lineEditConfirmPassword->text()) !=0){
        QMessageBox::critical(this,"Erreur","password et confirmpassword different ",QMessageBox::Ok);
        return false;
    }


    if(login.compare("") == 0 ||  nom.compare("") ==0){

        QMessageBox::critical(this,"information","Saisissez votre nom et login",QMessageBox::Ok);
        return false;
    }
    return true;
}

bool UIResponsable::getRech(QString &rech){

    rech = ui->lineEditRechercher->text();
    if(rech.compare("") == 0){


    QMessageBox::critical(this,"information","Input rechercher est vide !",QMessageBox::Ok);
    return false;
    }

     return true;
}



bool  UIResponsable::getInputsClasse(int* identifiant,QString &nam,int* capacite){
     QString s = "";
    if(ui->lineEditId->text().compare("") !=0){
        *identifiant = s.toInt();
    }
    nam = ui->lineEdit_classe->text();
    *capacite = ui->lineEdit_capacite->text().toInt();

    if(nam.compare("") == 0){

        QMessageBox::critical(this,"information","Saisissez votre nom de classe ",QMessageBox::Ok);
        return false;
    }
    return true;
}

bool UIResponsable::getInputsModule(int* identifiant,QString &name_module,QString &matiere,QString &classe){
    QString s = "";
   if(ui->lineEditId->text().compare("") !=0){
       *identifiant = s.toInt();
   }
   name_module = ui->lineEdit_Module->text();
   matiere = ui->lineEdit_Matiere->text();
   classe = ui->comboBox_classe->currentText();
   if(name_module.compare("") == 0 || matiere.compare("")==0){

       QMessageBox::critical(this,"information","Saisissez votre name module ou matiere ",QMessageBox::Ok);
       return false;
   }
   return true;


}

void UIResponsable::effacerInputs(){

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



void  UIResponsable::notificationInfo(QString message){

    QMessageBox::information(this,"information",message);
}




void UIResponsable::on_tableView_activated(const QModelIndex &index)
{
    //dbAccess->open();
    QString val =  ui->tableView->model()->data(index).toString();
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/hp/Documents/Projet QT/gestion_Note/gestion_notes.db");
    ui->lineEditUsername->isHidden();
    // QSqlQuery query(dbAccess->database());
     //query.prepare("SELECT identifiant, nom, prenom, login, type, date_Naiss, Tel, Sexe, Lieu_Naiss, Numero_CNI FROM t_users WHERE identifiant='"+val+"' or nom='"+val+"' or prenom='"+val+"' or login='"+val+"' or type='"+val+"' ");
     //query.exec();
    db.open();
   // qDebug() << db.lastError();
   // qDebug() << "DBAccess Object created and 'gestion_notes.db' has been added as default database!";
    QSqlQuery query;

    query.exec( "SELECT identifiant, nom, prenom, login, type, date_Naiss, Tel, Sexe, Lieu_Naiss, Numero_CNI, Matricule FROM t_users WHERE identifiant='"+val+"' or nom='"+val+"' or prenom='"+val+"' or login='"+val+"' or type='"+val+"' or Matricule ='"+val+"' ");

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
           ui->lineEdit_Matricule->setText(query.value(10).toString());
       }
     //dbAccess->close();
}


void UIResponsable::setNam(QString login){

    ui->labelUtilisateurConnecte->setText(login);
}
