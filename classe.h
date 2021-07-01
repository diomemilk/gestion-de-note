#ifndef CLASSE_H
#define CLASSE_H
#include <QString>

class classe
{
private:
    uint id;
    QString nam;
    uint capacite;

public:
    classe();
    classe(uint,QString,uint);
    uint getId(){return id;}
    void setId( uint id){ this->id = id;}
    QString getNam(){return nam;}
    void setNam( QString nam){this->nam = nam;}
    uint getCapacite(){return capacite;}
    void setCapacite(uint capacite){this->capacite = capacite;}
};

#endif // CLASSE_H
