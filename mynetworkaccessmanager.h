#ifndef MYNETWORKACCESSMANAGER_H
#define MYNETWORKACCESSMANAGER_H

#include <QNetworkAccessManager>
#include <QUrl>
#include <qnetworkreply.h>
#include <qauthenticator.h>
#include <qnetworkreply.h>
#include <qsslerror.h>

class	NetworkAccessViewer;

struct OffileDataStruct
{
	QUrl					url;
	QMap<QByteArray,QByteArray>	headers;
	QByteArray				data;

	OffileDataStruct(){}

	OffileDataStruct(const QNetworkRequest& req, QByteArray dt)
	{
		url = req.url();
		
		QByteArray header;
		foreach( header, req.rawHeaderList() ) 
		{
			headers[header] = req.rawHeader( header );
		}
		data = dt;
	}
};

class MyNetworkAccessManager : public QNetworkAccessManager
{
	Q_OBJECT

public:
	MyNetworkAccessManager(QObject *parent);
	~MyNetworkAccessManager();
    void setOfflineMode(bool state);
	void rePostRequestsToServer();
protected:
	QNetworkReply * createRequest ( Operation op, const QNetworkRequest & req, QIODevice * outgoingData = 0 );


private:
	NetworkAccessViewer *viewer;
	QMainWindow *mainWindow;
	QList<OffileDataStruct> offileDataList;
	bool offlineMode;

public slots:
	void slotError(QNetworkReply::NetworkError);
    void slotProxyAuthenticationRequired(const QNetworkProxy &proxy, QAuthenticator *authenticator);
	void slotSslErrors(QNetworkReply *reply, const QList<QSslError> &errors);
	void slotOnFinished(QNetworkReply* reply);
		

};

#endif // MYNETWORKACCESSMANAGER_H
