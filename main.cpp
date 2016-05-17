#include "stdafx.h"
#include "idchybridcontainer.h"
#include <QtGui/QApplication>
#include <QtNetwork\qsslsocket.h>
#include <QtSql\qsqldatabase.h>
#include <QtSql\qsqlquery.h>
#include <QtSql\qsqlerror.h>
#include <QtDebug>



int main(int argc, char *argv[])
{


	//QSqlDatabase db = QSqlDatabase::addDatabase( "QSQLITE" );

	//db.setDatabaseName( "./testdatabase.db" );

	//if( !db.open() )
	//{
	//	qDebug() << db.lastError();
	//	qFatal( "Failed to connect." );
	//}
 //   
	//qDebug( "Connected!" );
 // 
	//QSqlQuery qry;

	//qry.prepare( "CREATE TABLE IF NOT EXISTS names (id INTEGER UNIQUE PRIMARY KEY, firstname VARCHAR(30), lastname VARCHAR(30))" );
	//if( !qry.exec() )
	//	qDebug() << qry.lastError();
	//else
	//	qDebug() << "Table created!";
 //   
	//qry.prepare( "INSERT INTO names (id, firstname, lastname) VALUES (1, 'John', 'Doe')" );
	//if( !qry.exec() )
	//	qDebug() << qry.lastError();
	//else
	//	qDebug( "Inserted!" );






















	bool t = QSslSocket::supportsSsl() ;

    QApplication app(argc, argv);
    QUrl url;

    if (argc > 1)
        url = QUrl(argv[1]);
    else
		//url = QUrl("http://mahwebapps.inside.ups.com/opsysapps/");
		
		//url = QUrl("http://sidewinder.inside.ups.com/upsapps");
		
		url = QUrl("https://www.dcu.org/");
		//url = QUrl("file:///D:/InternationalDataCapture/IdcReferenceArchitcture/IdcHybridContainer/Test.htm");
		//url = QUrl("file:///C:/Qt/2010.05/qt/examples/webkit/formextractor/form.html?gender=Female");
		//url = QUrl("file:///D:/InternationalDataCapture/IdcReferenceArchitcture/IdcClient/IDCMainScreen.htm");
		//url = QUrl("http://10.246.211.168:8080/IdcClient/IDCMainScreen.htm");
        //url = QUrl("file:///D:/InternationalDataCapture/IdcReferenceArchitcture/IdcClient/test.html");

    IdcHybridContainer *browser = new IdcHybridContainer(url);
    browser->show();
    return app.exec();
}
