#ifndef MAINFORMATEUR_H
#define MAINFORMATEUR_H

#include <QMainWindow>
#include <QSqlDatabase>
#include "QSqlQueryModel"
#include "dbaccess.h"

namespace Ui {
class MainFormateur;
}

class MainFormateur : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainFormateur(QWidget *parent = nullptr);
    MainFormateur(QObject *controller = nullptr);
    ~MainFormateur();
    bool getInputsGf(int* identifiant,QString &matiere,QString &classe,QString &jour,QString &heure,QString &matricule, bool* operation);
    void notificationInfo(QString message);
    void getTable(QSqlQueryModel* model );
    void getTableclasse(QSqlQueryModel* model );

private slots:
    void on_tableView_activated(const QModelIndex &index);

private:
    Ui::MainFormateur *ui;
    QSqlDatabase db;
};

#endif // MAINFORMATEUR_H
