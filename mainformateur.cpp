#include "mainformateur.h"
#include "ui_mainformateur.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include "QMessageBox"

MainFormateur::MainFormateur(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainFormateur)
{
    ui->setupUi(this);
}

MainFormateur::MainFormateur(QObject *controller)
    : ui(new Ui::MainFormateur)
{
    ui->setupUi(this);


     connect(ui->pushButtonValider, SIGNAL(clicked()), controller, SLOT(onFormatuerEnregisterClicked()));

     connect(ui->pushButtonLister, SIGNAL(clicked()), controller, SLOT(onFormatuerListerGFClicked()));

     connect(ui->pushButtonExit, SIGNAL(clicked()), controller, SLOT(onFormatuerExitClicked()));

     connect(ui->pushButtonRetour, SIGNAL(clicked()), controller, SLOT(onFormatuerRetourClicked()));


}

void MainFormateur::getTableclasse(QSqlQueryModel *model){

     ui->comboBox_classe->setModel(model);

}

void MainFormateur::getTable(QSqlQueryModel* model ){

     ui->tableView->setModel(model);

}

bool MainFormateur::getInputsGf(int* identifiant,QString &matiere,QString &classe,QString &jour,QString &heure,QString &matricule,bool* operation){

    if(ui->lineEdit_Id->text().compare("") !=0){
        *identifiant = ui->lineEdit_Id->text().toInt();
    }

    matiere=ui->lineEdit_Matiere->text();
    matricule = ui->lineEdit_matr->text();
    classe = ui->comboBox_classe->currentText();
    jour = ui->comboBox_jour->currentText();
    heure = ui->comboBox_heure->currentText();
     *operation = ui->radioButtonCreer->isChecked();

    if(matricule.compare("") == 0){

        QMessageBox::critical(this,"information","Saisissez Matricule de Formateur",QMessageBox::Ok);
        return false;
    }
    return true;
}

void  MainFormateur::notificationInfo(QString message){

    QMessageBox::information(this,"information",message);
}

MainFormateur::~MainFormateur()
{
    delete ui;
}

void MainFormateur::on_tableView_activated(const QModelIndex &index)
{
    //dbAccess->open();
    QString val =  ui->tableView->model()->data(index).toString();
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/hp/Documents/Projet QT/gestion_Note/gestion_notes.db");
    //ui->lineEditUsername->isHidden();
    // QSqlQuery query(dbAccess->database());
     //query.prepare("SELECT identifiant, nom, prenom, login, type, date_Naiss, Tel, Sexe, Lieu_Naiss, Numero_CNI FROM t_users WHERE identifiant='"+val+"' or nom='"+val+"' or prenom='"+val+"' or login='"+val+"' or type='"+val+"' ");
     //query.exec();
    db.open();
    qDebug() << db.lastError();
    qDebug() << "DBAccess Object created and 'gestion_notes.db' has been added as default database!";
    QSqlQuery query;

    query.exec( "SELECT id,Matiere, matricule FROM G_formateur WHERE id='"+val+"' or Matiere='"+val+"' or matricule='"+val+"' or jour='"+val+"' or matricule='"+val+"' or heure='"+val+"' ");

    while(query.next()){
           ui->lineEdit_Id->setText(query.value(0).toString());
           ui->lineEdit_Matiere->setText(query.value(1).toString());
           ui->lineEdit_matr->setText(query.value(2).toString());

       }
     //dbAccess->close();
}
