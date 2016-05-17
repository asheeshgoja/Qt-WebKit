#include "StdAfx.h"

#include <qdebug.h>
#include <qnetworkrequest.h>
#include <qnetworkreply.h>
#include <qsignalmapper.h>

#include "networkaccessviewer.h"

NetworkAccessViewer::NetworkAccessViewer(QWidget *parent)
{
    dialog = new QDialog();
    networkRequestsDialog = new Ui::NetworkAccessViewer;
    networkRequestsDialog->setupUi(dialog);
    dialog->show();

    mapper = new QSignalMapper(this);
    connect( mapper, SIGNAL(mapped(QObject *)), SLOT(requestFinished(QObject *)) );
   


	networkRequestsDialog->requestList->setSizePolicy(QSizePolicy::Expanding, networkRequestsDialog->requestList->sizePolicy().verticalPolicy() );

    connect( networkRequestsDialog->requestList, SIGNAL( currentItemChanged( QTreeWidgetItem*, QTreeWidgetItem* ) ), SLOT( showItemDetails( QTreeWidgetItem *) ) );
    connect( networkRequestsDialog->clearButton, SIGNAL( clicked() ), SLOT( clear() ) );
	
	//ag
	mapper2 = new QSignalMapper(this);
    connect( mapper2, SIGNAL(mapped(QObject *)), SLOT(readyRead(QObject *)) );
}

NetworkAccessViewer::~NetworkAccessViewer()
{
    delete networkRequestsDialog;
    delete dialog;
}

void NetworkAccessViewer::addRequest( QNetworkAccessManager::Operation op, const QNetworkRequest& req, QIODevice *outgoingData, QNetworkReply *reply )
{
    // Add to list of requests
    QStringList cols;
    switch( op ) {
    case   QNetworkAccessManager::HeadOperation:
        cols << QString::fromLatin1("HEAD");
        break;
    case   QNetworkAccessManager::GetOperation:
        cols << QString::fromLatin1("GET");
        break;
    case   QNetworkAccessManager::PutOperation:
        cols << QString::fromLatin1("PUT");
        break;
    case   QNetworkAccessManager::PostOperation:
        cols << QString::fromLatin1("POST");
        break;
    default:
        qWarning() << "Unknown network operation";
    }
    cols << req.url().toString();
    cols << tr("Pending");

    QTreeWidgetItem *item = new QTreeWidgetItem( cols );
    networkRequestsDialog->requestList->addTopLevelItem( item );

    // Add to maps
    requestMap.insert( reply, req );
    itemMap.insert( reply, item );
    itemRequestMap.insert( item, req );

    mapper->setMapping( reply, reply );
    connect( reply, SIGNAL( finished() ), mapper, SLOT( map() ) );
	
	
	//ag
    mapper2->setMapping( reply, reply );
    connect( reply, SIGNAL( readyRead() ), mapper2, SLOT( map() ) );


}

void NetworkAccessViewer::show()
{
    dialog->show();
}

void NetworkAccessViewer::hide()
{
    dialog->hide();
}

void NetworkAccessViewer::clear()
{
    requestMap.clear();
    itemMap.clear();
    itemReplyMap.clear();
    itemRequestMap.clear();
	responseDataMap.clear();
    networkRequestsDialog->requestList->clear();
    networkRequestsDialog->requestDetails->clear();
    networkRequestsDialog->responseDetails->clear();
	networkRequestsDialog->textEditResponseData->clear();

}

void NetworkAccessViewer::requestFinished( QObject *replyObject )
{
    QNetworkReply *reply = qobject_cast<QNetworkReply *>( replyObject );


    if ( !reply ) {
        qWarning() << "Failed to downcast reply";
        return;
    }

    QTreeWidgetItem *item = itemMap[reply];

    // Record the reply headers
    QList<QByteArray> headerValues;
    QByteArray header;
    foreach( header, reply->rawHeaderList() ) {
        headerValues += reply->rawHeader( header );
    }
    QPair< QList<QByteArray>, QList<QByteArray> > replyHeaders;
    replyHeaders.first = reply->rawHeaderList();
    replyHeaders.second = headerValues;
    itemReplyMap[item] = replyHeaders;

    // Display the request
    int status = reply->attribute( QNetworkRequest::HttpStatusCodeAttribute ).toInt();
    QString reason = reply->attribute( QNetworkRequest::HttpReasonPhraseAttribute ).toString();
    item->setText( 2, tr("%1 %2").arg(status).arg(reason) );

    QString length = reply->header( QNetworkRequest::ContentLengthHeader ).toString();
    item->setText( 3, length );

    QString contentType = reply->header( QNetworkRequest::ContentTypeHeader ).toString();
    item->setText( 4, contentType );

    if ( status == 302 ) {
        QUrl target = reply->attribute( QNetworkRequest::RedirectionTargetAttribute ).toUrl();
        item->setText( 5, tr("Redirect: %1").arg( target.toString() ) );
    }
}

void NetworkAccessViewer::readyRead(QObject* replyObject )
{
    QNetworkReply *reply = qobject_cast<QNetworkReply *>( replyObject );
	

	QTreeWidgetItem *item = itemMap[reply];


	QByteArray result;
	qint64 readBytes = 0;            
	qint64 readResult;


	result.resize(result.size() + Q_INT64_C(16384) );
	readResult = reply->peek(result.data() + readBytes, result.size() - readBytes);
	result.resize(int(readResult));


	QString strData(result);
	responseDataMap[item] = result;

}


void NetworkAccessViewer::showItemDetails( QTreeWidgetItem *item )
{
    // Show request details
    QTreeWidget *reqTree = networkRequestsDialog->requestDetails;
    reqTree->clear();

    QNetworkRequest req = itemRequestMap[item];
    QByteArray header;
    foreach( header, req.rawHeaderList() ) {
        QTreeWidgetItem *item = new QTreeWidgetItem();
        item->setText( 0, QString::fromLatin1( header ) );
        item->setText( 1, QString::fromLatin1( req.rawHeader( header ) ) );
        reqTree->addTopLevelItem( item );
    }

    // Show reply headers
    QTreeWidget *respTree = networkRequestsDialog->responseDetails;
    respTree->clear();

    QPair< QList<QByteArray>, QList<QByteArray> > replyHeaders = itemReplyMap[item];
    for ( int i = 0; i < replyHeaders.first.count(); i++ ) {
        QTreeWidgetItem *item = new QTreeWidgetItem();
        item->setText( 0, QString::fromLatin1( replyHeaders.first[i] ) );
        item->setText( 1, QString::fromLatin1( replyHeaders.second[i] ) );
        respTree->addTopLevelItem( item );
    }

	//ag
	QByteArray& bytes = responseDataMap[item];
	QString strData(bytes);
	networkRequestsDialog->textEditResponseData->setPlainText(strData);
}


void NetworkAccessViewer::on_clearButton_clicked()
{

}

