#include "profile.h"
#include "ui_profile.h"
#include "QMessageBox"

profile::profile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::profile)
{
    ui->setupUi(this);

}
profile::profile(QObject *controller)
    : ui(new Ui::profile)
{
    ui->setupUi(this);
    connect(ui->pushButton_retour, SIGNAL(clicked()), controller, SLOT(onUIAdministrateurRetourClicked()));
    connect(ui->pushButton_valider_2, SIGNAL(clicked()), controller, SLOT(ModifierProfileClicked()));

    connect(ui->pushButton_valider, SIGNAL(clicked()), controller, SLOT(ModifierPasswordClicked()));
}

profile::~profile()
{
    delete ui;
}

void profile::getUser(User user)
{
    int id = user.getIdentifiant();


    ui->username->setText(user.getNom());
    ui->prenom->setText(user.getPrenom());
    ui->login->setText(user.getLogin());
    ui->lineEditUsername->setText(user.getNom());
    ui->lineEditprenome->setText(user.getPrenom());
    ui->lineEditLogin->setText(user.getLogin());
    ui->lineEdit_Tel->setText(user.getTel());
    ui->lineEditId->setText(QString("%1").arg(id));
    ui->groupBox_2->hide();
    ui->groupBox_4->hide();
}


void profile::on_pushButton_clicked()
{
    bool hide = true;

    if(hide == true){
        ui->groupBox_2->show();
    }

}



void profile::on_pushButton_2_clicked()
{
    bool hide = true;

    if(hide == true){
        ui->groupBox_4->show();
    }
}

bool profile::getInputs(int* identifiant,QString &nom,QString &prenom, QString &login, QString &Tel){

    if(ui->lineEditId->text().compare("") !=0){
        *identifiant = ui->lineEditId->text().toInt();

    }

    login = ui->lineEditLogin->text();

    nom = ui->lineEditUsername->text();

    prenom = ui->lineEditprenome->text();



    Tel =  ui->lineEdit_Tel->text();



    if(login.compare("") == 0 ||  nom.compare("") ==0){

        QMessageBox::critical(this,"information","Saisissez votre nom et login",QMessageBox::Ok);
        return false;
    }
    return true;
}



void  profile::notificationInfo(QString message){

    QMessageBox::information(this,"information",message);
}

bool profile::getIputPassword(QString &password,QString &niveauPassword, QString &dexiemePassword)
{
    password = ui->lineEditPassword->text();
    niveauPassword = ui->lineEditNiveauPassword->text();
    dexiemePassword = ui->lineEditPassword_2->text();
    if(password.compare("") == 0 || niveauPassword.compare("") == 0){
        QMessageBox::critical(this,"information","Saisissez votre password et NiveuauPassword",QMessageBox::Ok);
        return false;
    }
    return true;
}


