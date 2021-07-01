#ifndef UIRESPONSABLE_H
#define UIRESPONSABLE_H

#include <QMainWindow>
#include <QSqlDatabase>
#include "QSqlQueryModel"
#include "dbaccess.h"
namespace Ui {
class UIResponsable;
}

class UIResponsable : public QMainWindow
{
    Q_OBJECT

public:
    explicit UIResponsable(QWidget *parent = nullptr);
             UIResponsable(QObject *controller = nullptr);
        void getTableEtudiant(QSqlQueryModel* model );
        void getTableFormatuer(QSqlQueryModel* model );
        void getTableclasse(QSqlQueryModel* model );
         void getTableRech(QSqlQueryModel* model );
        bool getRech(QString &rech);
        void notificationInfo(QString message);
        void setNam(QString login);
        bool getInputs(int* identifiant,QString &nom,QString &prenom, QString &login,QString &password,QString &type,  QString &dates_Naiss, QString &Tel, QString &Sexe, QString &Lieu_Nais, int* CNI, bool* operation,QString &Matricule);
            ~UIResponsable();
        bool getInputsClasse(int* identifiant,QString &nam,int* capacite);
        bool getInputsModule(int* identifiant,QString &name_module,QString &matiere,QString &classe);
         void effacerInputs();

private slots:
     void on_tableView_activated(const QModelIndex &index);

private:
    Ui::UIResponsable *ui;
    QSqlDatabase db;
     DBAccess *dbAccess;
};

#endif // UIRESPONSABLE_H
