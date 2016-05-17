#include "stdafx.h"

#include <QBuffer>
#include <QTimer>

#include "qcustomnetworkreply.h"

struct QCustomNetworkReplyPrivate
{
    QByteArray content;
    qint64 offset;
};

QCustomNetworkReply::QCustomNetworkReply( QObject *parent )
    : QNetworkReply(parent)
{
    d = new QCustomNetworkReplyPrivate;
}

QCustomNetworkReply::~QCustomNetworkReply()
{
    delete d;
}

void QCustomNetworkReply::setHttpStatusCode( int code, const QByteArray &statusText )
{
    setAttribute( QNetworkRequest::HttpStatusCodeAttribute, code );
    if ( statusText.isNull() )
        return;

    setAttribute( QNetworkRequest::HttpReasonPhraseAttribute, statusText );
}

void QCustomNetworkReply::setHeader( QNetworkRequest::KnownHeaders header, const QVariant &value )
{
    QNetworkReply::setHeader( header, value );
}

void QCustomNetworkReply::setUrl(QUrl url )
{
    QNetworkReply::setUrl(url);
}

void QCustomNetworkReply::setRawHeader(const QByteArray &headerName, const QByteArray &headerValue)
{
    QNetworkReply::setRawHeader( headerName, headerValue );
}

void QCustomNetworkReply::setContentType( const QByteArray &contentType )
{
    setHeader(QNetworkRequest::ContentTypeHeader, contentType);
}

void QCustomNetworkReply::setContent( const QString &content )
{
    setContent(content.toUtf8());
}

void QCustomNetworkReply::setOperation(QNetworkAccessManager::Operation op )
{
    QNetworkReply::setOperation(op);
}

void QCustomNetworkReply::setRequest(QNetworkRequest req )
{
    QNetworkReply::setRequest(req);
}

qint64 QCustomNetworkReply::writeData(const char *data, qint64 len)
{
   return  QNetworkReply::writeData(data,  len);
}

void QCustomNetworkReply::setContent( const QByteArray &content )
{
    d->content = content;
    d->offset = 0;

    open(ReadOnly | Unbuffered);
    //setHeader(QNetworkRequest::ContentLengthHeader, QVariant(content.size()));

    QTimer::singleShot( 0, this, SIGNAL(readyRead()) );
    QTimer::singleShot( 0, this, SIGNAL(finished()) );
}

void QCustomNetworkReply::abort()
{
    // NOOP
}


qint64 QCustomNetworkReply::bytesAvailable() const
{
    return d->content.size() ;//- d->offset;
}

bool QCustomNetworkReply::isSequential() const
{
    return true;
}


qint64 QCustomNetworkReply::readData(char *data, qint64 maxSize)
{
    if (d->offset >= d->content.size())
        return -1;

    qint64 number = qMin(maxSize, d->content.size() - d->offset);
    memcpy(data, d->content.constData() + d->offset, number);
    d->offset += number;

    return number;
}
