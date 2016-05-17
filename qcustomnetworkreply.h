#ifndef QCUSTOMNETWORKREPLY_H
#define QCUSTOMNETWORKREPLY_H

#include <qnetworkaccessmanager.h>
#include <QNetworkReply>
#include <qnetworkrequest.h>

class QCustomNetworkReply : public QNetworkReply
{
    Q_OBJECT

public:
    QCustomNetworkReply( QObject *parent = 0 );
    ~QCustomNetworkReply();

    void setHttpStatusCode( int code, const QByteArray &statusText = QByteArray() );
    void setHeader( QNetworkRequest::KnownHeaders header, const QVariant &value );
	void setRawHeader(const QByteArray &headerName, const QByteArray &headerValue);
    void setContentType( const QByteArray &contentType );

    void setContent( const QString &content );
    void setContent( const QByteArray &content );
    void setOperation(QNetworkAccessManager::Operation op );
	void setRequest(QNetworkRequest req );
	void setUrl(QUrl url );

	qint64 writeData(const char *data, qint64 len);


    void abort();
    qint64 bytesAvailable() const;
    bool isSequential() const;

protected:
    qint64 readData(char *data, qint64 maxSize);

private:
    struct QCustomNetworkReplyPrivate *d;
};


#endif // QCUSTOMNETWORKREPLY_H
