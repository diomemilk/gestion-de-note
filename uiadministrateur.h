#ifndef UIADMINISTRATEUR_H
#define UIADMINISTRATEUR_H

#include <QMainWindow>
#include "QSqlQueryModel"
#include <QSqlDatabase>

namespace Ui {
class UIAdministrateur;
}

class UIAdministrateur : public QMainWindow
{
    Q_OBJECT

public:
    // rega_explicit
    UIAdministrateur(QWidget *parent = nullptr);
    UIAdministrateur(QObject *controller = nullptr);
    ~UIAdministrateur();
    bool getInputs(int* identifiant,QString &nom,QString &prenom, QString &login,QString &password,QString &type,  QString &dates_Naiss, QString &Tel, QString &Sexe, QString &Lieu_Nais, int* CNI, bool* operation,QString &Matricule);
    bool getId(int* identifiant,QString &login);
    bool getRech(QString &rech);
    void setNam(QString login);
    void getTable(QSqlQueryModel* model );
    void getTableRech(QSqlQueryModel* model );
    void effacerInputs();
    void notificationInfo(QString message);


private slots:
    void on_tableView_activated(const QModelIndex &index);


private:
    Ui::UIAdministrateur *ui;
    QSqlDatabase db;
    int index = -1;
};

#endif // UIADMINISTRATEUR_H
