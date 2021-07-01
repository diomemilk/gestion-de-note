#ifndef PROFILE_H
#define PROFILE_H
#include <QDialog>
#include <user.h>

namespace Ui {
class profile;
}

class profile : public QDialog
{
    Q_OBJECT

public:
    explicit profile(QWidget *parent = nullptr);
    profile(QObject *controller = nullptr);
    ~profile();
    void getUser(User user);
    bool getInputs(int* identifiant,QString &nom,QString &prenom, QString &login, QString &Tel);
    void notificationInfo(QString message);
    bool getIputPassword(QString &password,QString &niveauPassword, QString &dexiemePassword);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::profile *ui;
};

#endif // PROFILE_H
