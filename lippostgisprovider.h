#ifndef LIPPOSTGISPROVIDER_H
#define LIPPOSTGISPROVIDER_H
#include <QSqlDatabase>
#include <QtSql/QSqlDatabase> //бд
#include <QtSql/QSqlError> //ошибки
#include <QtSql/QSqlQuery> //запросы
class LIPPostGisProvider
{
public:
    LIPPostGisProvider();
    /** Return true if connection was succsesful */
    bool isConnected();
    /** Return true if database have an postgis extension */
    bool isPostGIS();

    void connect();
public:

    QString connectionName;
    QString host;
    QString port;
    QString databaseName;
    QString userName;
    QString password;

private:
    bool mConnectionFlag;
    QSqlDatabase *mDb;


};

#endif // LIPPOSTGISPROVIDER_H
