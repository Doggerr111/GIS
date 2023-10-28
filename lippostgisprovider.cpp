#include "lippostgisprovider.h"
#include <QMessageBox>
LIPPostGisProvider::LIPPostGisProvider()
    : mConnectionFlag{false}
{
    mDb = new QSqlDatabase(QSqlDatabase::addDatabase("QPSQL"));
}

bool LIPPostGisProvider::isConnected()
{
    return mConnectionFlag;
}

bool LIPPostGisProvider::isPostGIS()
{
    if (!isConnected())
        return false;
    QSqlQuery query;
    query.exec("SELECT extname FROM pg_extension WHERE extname = 'postgis'");
    if (query.next())
        return true;
    return false;

}

void LIPPostGisProvider::connect()
{
    mDb->setDatabaseName(databaseName);
    mDb->setHostName(host);
    mDb->setUserName(userName);
    mDb->setPassword(password);
    mDb->setPort(port.toInt());

    if (mDb->isValid() && mDb->isDriverAvailable("QPSQL")) //если подключение успешное
        mConnectionFlag = true;
    else
    {
         QMessageBox::information(nullptr,"",mDb->lastError().text());
    }
    if (!mDb->open()) //если не подключились выводим сообщение об ошибке из бд
        mConnectionFlag=false;



}


