#include <QCoreApplication>
#include <Qtsql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtDebug>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Establishing MySQL Connectivity
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("game-boost.com");
    db.setUserName("gameboos_itcuser");
    db.setPassword("ITCTest123!");
    db.setDatabaseName("gameboos_itcalpha");

    //Connectivity tester
    if(db.open()){
        cout << "Connection to the DB has been established!" << endl;
    }
    else{
        cout << "Connection to the DB has failed!!!!!!" << endl;
    }

    //Adding Data to the Database
    // int used for writing, string used for reading
    // string id, kW, kWh, PQ
    int id[3]={1,2,3};
    int kW[3]={1,20,30};
    int kWh[3]={11,21,31};
    int PQ[3]={12,22,32};

    QSqlQuery mysqlquery;

    // Write arrays to DB
    mysqlquery.prepare("INSERT INTO SM (id, kW, kWh, PQ) "
                       "VALUES (:id, :kW, :kWh, :PQ)");

    for( int i = 0; i < 3; i++) {
        mysqlquery.bindValue(":id", id[i]);
        mysqlquery.bindValue(":kW", kW[i]);
        mysqlquery.bindValue(":kWh", kWh[i]);
        mysqlquery.bindValue(":PQ", PQ[i]);
        mysqlquery.exec();
        cout << "Data query " << i << " sucessfully sent!" << endl;
    }

    /* Section here is used to see the data from the database
    //
    if(mysqlquery.size()>0){
        while(mysqlquery.next()){
            id=mysqlquery.value("id").toString().toUtf8().constData();
            kW=mysqlquery.value("kW").toString().toUtf8().constData();
            kWh=mysqlquery.value("kWh").toString().toUtf8().constData();
            PQ=mysqlquery.value("PQ").toString().toUtf8().constData();

            cout << id << " - " << kW << " - " << kWh << " - " << PQ << endl;
        }

    }
    else{


    }
/**/

    return a.exec();
}
