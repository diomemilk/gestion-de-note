#ifndef MODULE_H
#define MODULE_H
#include <QString>

class Module
{
private:
    uint id;
    QString name_module;
    QString  matiere;
    QString classe;
public:
    Module();
     Module(uint,QString,QString,QString);
    uint getId(){return id;};
    void setId( uint id){this->id = id;};
    QString getName_module() {return name_module;};
    void setName_module(QString name_module){this->name_module = name_module;};
    QString getMatiere(){return matiere;};
    void setMatiere(QString matiere){this->matiere = matiere;};
    QString getClasse(){return classe;};
    void setClasse(QString classe){this->classe = classe;};
};

#endif // MODULE_H
