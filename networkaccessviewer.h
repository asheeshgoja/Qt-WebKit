#ifndef NETWORKACCESSVIEWER_H
#define NETWORKACCESSVIEWER_H

#include <QWidget>
#include "ui_networkaccessviewer.h"
#include <qnetworkrequest.h>
#include <qnetworkreply.h>
#include <qsignalmapper.h>

class NetworkAccessViewer : public QWidget
{
	Q_OBJECT

public:
	NetworkAccessViewer(QWidget *parent = 0);
	~NetworkAccessViewer();


    void addRequest( QNetworkAccessManager::Operation op, const QNetworkRequest&req, QIODevice *outgoingData, QNetworkReply *reply );

    void show();
    void hide();

private slots:
    void on_clearButton_clicked();
    void clear();
    void requestFinished( QObject *replyObject );
    void showItemDetails( QTreeWidgetItem *item );
    void readyRead( QObject * replyObject );

private:
    QDialog *dialog;
	Ui::NetworkAccessViewer *networkRequestsDialog;
    QMap<QNetworkReply *, QNetworkRequest> requestMap;
    QMap<QTreeWidgetItem *, QNetworkRequest> itemRequestMap;
    QMap<QNetworkReply *, QTreeWidgetItem *> itemMap;
    QMap<QTreeWidgetItem *, QPair< QList<QByteArray>, QList<QByteArray> > > itemReplyMap;
    QSignalMapper *mapper;
    QSignalMapper *mapper2;

	//ag
	QMap<QTreeWidgetItem *, QByteArray> responseDataMap;


};

#endif // NETWORKACCESSVIEWER_H
