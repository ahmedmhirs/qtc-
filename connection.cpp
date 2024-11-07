#include "connection.h"
#include<QSqlError>
Connection::Connection()
{

}

bool Connection::createconnect()
{
    db= QSqlDatabase::addDatabase("QODBC");
    bool test=false;
    db.setDatabaseName("projet");//inserer le nom de la source de données
    db.setUserName("system");//inserer nom de l'utilisateur
    db.setPassword("Ahmed2004**");//inserer mot de passe de cet utilisateur
    if(db.open())test=true;
    return test;


}
void Connection::closeConnection(){db.close();}
