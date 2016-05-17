#include "StdAfx.h"
#include "mynetworkaccessmanager.h"
#include "qurl.h"
#include "qnetworkproxy.h"
#include "qnetworkrequest.h"
#include "qmessagebox.h"
#include "networkaccessviewer.h"
#include "ui_ProxyCredentialsDialog.h"
#include "idchybridcontainer.h"
#include "qcustomnetworkreply.h"
#include "windows.h"


MyNetworkAccessManager::MyNetworkAccessManager(QObject *parent)
	: QNetworkAccessManager(parent)
{

	viewer = NULL;

	mainWindow = (QMainWindow*)parent;

	offlineMode = ((IdcHybridContainer*)mainWindow)->getOfflineMode() ;


	//viewer = new NetworkAccessViewer((QWidget*)parent);
	
	connect(this, SIGNAL(finished(QNetworkReply*)), this, SLOT(slotOnFinished(QNetworkReply*)));
	connect(this, SIGNAL(proxyAuthenticationRequired(QNetworkProxy,QAuthenticator*)), this, SLOT(slotProxyAuthenticationRequired(QNetworkProxy,QAuthenticator*)));   
	connect(this, SIGNAL(sslErrors(QNetworkReply*,QList<QSslError>)), this, SLOT(slotSslErrors(QNetworkReply*,QList<QSslError>)));

}

MyNetworkAccessManager::~MyNetworkAccessManager()
{

}

void MyNetworkAccessManager::slotError(QNetworkReply::NetworkError e)
{

}

QNetworkReply * MyNetworkAccessManager::createRequest ( Operation op, const QNetworkRequest & req, QIODevice * outgoingData )
{
	if( offlineMode && (op == QNetworkAccessManager::PutOperation) )
	{

		QByteArray result;
		qint64 readBytes = 0;            
		qint64 readResult;

        result.resize(result.size() + Q_INT64_C(16384) );
        readResult = outgoingData->peek(result.data() + readBytes, result.size() - readBytes);
		result.resize(int(readResult));
		
		offileDataList.push_back( OffileDataStruct(req,result) );
	}

	if(offlineMode) 
	{
	    QCustomNetworkReply *reply = new QCustomNetworkReply();
        reply->setHttpStatusCode(200, "OK" );
        reply->setUrl( req.url() );
        reply->setRequest(req);

		//reply->setRawHeader(QString("Transfer-Encoding").toAscii(),QString("chunked").toAscii() );
		//reply->setRawHeader(QString("Cache-Control").toAscii(),QString("no-cache").toAscii() );
		//reply->setRawHeader(QString("Date").toAscii(),QString("Fri, 17 Dec 2010 18:50:37 GMT").toAscii() );
		//reply->setRawHeader(QString("Accept-Ranges").toAscii(),QString("bytes").toAscii() );
		//reply->setRawHeader(QString("Server").toAscii(),QString("Restlet-Framework/2.0.1").toAscii() );
		//reply->setRawHeader(QString("Vary").toAscii(),QString("Accept-Charset, Accept-Encoding, Accept-Language, Accept").toAscii() );
		//reply->setRawHeader(QString("Content-Type").toAscii(),QString("application/json; charset=UTF-8").toAscii() );


		reply->setContent( QString("{\"pkg_id\":null,\"ke_cntry_slic\":null,\"RKE\":null,\"sort\":null,\"sort_date\":null,\"src\":\"src-offline\",\"mnfs_no\":null,\"import_ctry\":null,\"service_level\":null,\"trans\":null,\"dt\":null,\"pymt\":null,\"pcs\":null,\"ShptWt\":0.0,\"ShipmentDate\":null,\"Time\":null,\"Description\":null,\"Reference1\":null,\"Reference2\":null,\"DA_ID\":null,\"Slp\":null,\"ExportHoldRelease\":false,\"EAM\":false,\"AqSrc\":null,\"ShipperInfo\":{\"ShipperAccountNo\":null,\"Country\":null,\"Address\":{\"Line1\":null,\"Line2\":null,\"Line3\":null,\"City\":null,\"State\":null,\"Postal\":null,\"Telephone\":null,\"Fax\":null},\"Contact\":null,\"OriginSlic\":0,\"ExportSlic\":0},\"ImporterInfo\":{\"Country\":null,\"ImporterAccountNo\":null,\"ResidentialSurcharge\":false,\"Lookup\":false,\"Contact\":null,\"Address\":{\"Line1\":null,\"Line2\":null,\"Line3\":null,\"City\":null,\"State\":null,\"Postal\":null,\"Telephone\":null,\"Fax\":null},\"Broker\":null,\"ImporterID\":null,\"DestinationSlic\":0,\"ImportSlic\":0},\"SurchargeInfo\":{\"CreditCardNo\":null,\"ExpirationDate\":null,\"MRNNo\":null,\"SED_Required\":false,\"SEDPreparedByUps\":false,\"AES_TransactionNo\":null},\"SoldToInfo\":{\"ImporterAccountNo\":null,\"Lookup\":false,\"SoldToName\":null,\"SoldToAddress\":null,\"Broker\":null},\"ThirdPartyInfo\":{\"BillTransportation_ShippersPortionTo\":null,\"BillDutiesAndTaxes_ReceiversPortionTo\":null},\"Packages\":[],\"InvoiceInfo\":{\"ExportID_EIN\":null,\"CntryUltimateDestination\":null,\"InsuranceCharge\":null,\"FreightCharge\":null,\"DiscountRebate\":null,\"TermsOfShipment\":null,\"FaxSent\":false,\"InvoiceLines\":[]},\"GlobalDetailInfo\":{\"Name\":null},\"shipment_id\":\"OFFLINE\",\"weight\":0}") );
		
		if( viewer != NULL)
			viewer->addRequest( op, req, outgoingData, reply );

        return reply;
	}


	QUrl url = req.url();
	QString host = url.host();


	QNetworkReply *reply = QNetworkAccessManager::createRequest( op, req, outgoingData );
	
	if( viewer != NULL)
		viewer->addRequest( op, req, outgoingData, reply );

    //connect(reply,	SIGNAL( error(QNetworkReply::NetworkError)), 
	//		this,   SLOT(slotError(QNetworkReply::NetworkError) ));

	return reply;//QNetworkAccessManager::createRequest(op, req, outgoingData);
}



void MyNetworkAccessManager::slotProxyAuthenticationRequired(const QNetworkProxy &proxy, QAuthenticator *authenticator)
{
	
    QDialog dialog(mainWindow);
    dialog.setWindowFlags(Qt::Sheet);

    Ui_ProxyCredentialsDialog  proxyDialog;
    proxyDialog.setupUi(&dialog);

    QString introMessage = tr("<qt>Connect to proxy \"%1\" using:</qt>");
    introMessage = introMessage.arg(Qt::escape(proxy.hostName()));
    proxyDialog.introLabel->setText(introMessage);
    proxyDialog.introLabel->setWordWrap(true);

    if (dialog.exec() == QDialog::Accepted) {
        authenticator->setUser(proxyDialog.userName->text());
        authenticator->setPassword(proxyDialog.password->text());
	}
}


void MyNetworkAccessManager::slotSslErrors(QNetworkReply *reply, const QList<QSslError> &error)
{
	static QString ignore_host;

	//BrowserMainWindow *mainWindow = BrowserApplication::instance()->mainWindow();
	//if (mainWindow && mainWindow->currentTab())
	//	mainWindow->currentTab()->setSslErrors();

	QSettings settings;
	settings.beginGroup(QLatin1String("ApprovedSSL"));

	if (reply->url().host() == ignore_host || settings.value(reply->url().host(), false) == true )
	{
		reply->ignoreSslErrors();
		return;
	}

    QStringList errorStrings;
    for (int i = 0; i < error.count(); ++i)
        errorStrings += error.at(i).errorString();
    QString errors = errorStrings.join(QLatin1String("\n"));
    int ret = QMessageBox::warning(mainWindow, QCoreApplication::applicationName(),
		tr("Secure connection errors (SSL):\n\nProblem host:  %1\n\n%2\n\n"
							"Do you want to approve this SSL certificate and load the web page?\n"
							"(approving ignores these errors for this particular site in a future)").arg(reply->url().host()).arg(errors),
                           QMessageBox::Yes | QMessageBox::No,
                           QMessageBox::No);
    if (ret == QMessageBox::Yes)
	{
		reply->ignoreSslErrors();
		ignore_host = reply->url().host();
		settings.setValue(ignore_host, true);
	}
}

void MyNetworkAccessManager::setOfflineMode(bool state)
{
	offlineMode = state;
	//((IdcHybridContainer*)mainWindow)->setOfflineMode(state) ;
}

void MyNetworkAccessManager::rePostRequestsToServer()
{
	OffileDataStruct s;
	foreach(s,offileDataList)
	{
		QNetworkRequest req(s.url);

		QMap<QByteArray, QByteArray>::iterator i = s.headers.begin();
		while (i != s.headers.end()) 
		{
			req.setRawHeader(i.key(),i.value() );
			++i;
		}

		this->post(req,s.data);
	}

	offileDataList.clear();
}


void MyNetworkAccessManager::slotOnFinished(QNetworkReply* reply)
{	
	
	//QNetworkReply::NetworkError e =  reply->error();
	//QString host = reply->url().host() ;


	//if (( e == QNetworkReply::ConnectionRefusedError )||
 //       ( e == QNetworkReply::ConnectionRefusedError )||
 //       ( e == QNetworkReply::RemoteHostClosedError)||
 //       ( e == QNetworkReply::HostNotFoundError)||
 //       ( e == QNetworkReply::TimeoutError)||
 //       ( e == QNetworkReply::OperationCanceledError)||
 //       ( e == QNetworkReply::SslHandshakeFailedError)||
 //       ( e == QNetworkReply::TemporaryNetworkFailureError)||
 //       ( e == QNetworkReply::UnknownNetworkError))
	//{
	//	
	//	if( ( reply->operation() == QNetworkAccessManager::PostOperation)||
	//		( reply->operation() == QNetworkAccessManager::PutOperation))
	//	{
	//		int ret = QMessageBox::warning(mainWindow, QCoreApplication::applicationName(),
	//							"Host " + reply->url().host() + " is not avalible. \nDo you wish to switch to offline mode and store data locally ?",
	//						   QMessageBox::Yes | QMessageBox::No,
	//						   QMessageBox::No);

	//		if (ret == QMessageBox::Yes)
	//		{		
	//		
	//			FLASHWINFO finfo;
	//			finfo.cbSize = sizeof( FLASHWINFO );
	//			finfo.hwnd = mainWindow->winId();
	//			finfo.uCount = 20; // Flash 20 times
	//			finfo.dwTimeout = 400; // Duration in milliseconds between flashes
	//			finfo.dwFlags = FLASHW_ALL; //Flash only taskbar button
	//			::FlashWindowEx( &finfo );

	//			mainWindow->setWindowTitle("Offline Mode Active : UPS Smart Web Container");

	//			setOfflineMode(true);
	//			return;
	//		}
	//	}
	//}
	 

	//setOfflineMode(false);


	QVariant possibleRedirectUrl =   reply->attribute(QNetworkRequest::RedirectionTargetAttribute);
	QUrl _urlRedirectedTo = possibleRedirectUrl.toUrl();


	if(!_urlRedirectedTo.isEmpty()) 
	{
		get(QNetworkRequest(_urlRedirectedTo));
	}
	else 
	{
		int status = reply->attribute( QNetworkRequest::HttpStatusCodeAttribute ).toInt();
		QString reason = reply->attribute( QNetworkRequest::HttpReasonPhraseAttribute ).toString();
		QString ses(tr("%1 %2").arg(status).arg(reason) );

	}



	reply->deleteLater();
}