#ifndef IDCHYBRIDCONTAINER_H
#define IDCHYBRIDCONTAINER_H

#include <QtGui/QMainWindow>
#include "ui_idchybridcontainer.h"
#include <QtGui>
#include <QHash>
#include <QMainWindow>
#include <QTextDocumentFragment>
#include <qnetworkproxy.h>
#include <mynetworkaccessmanager.h>

class QAction;
class QTextDocument;
class QTextEdit;
class QWebView;
class QextSerialPort;
class QNetworkAccessManager;

class IdcHybridContainer : public QMainWindow
{
	Q_OBJECT

public:
	IdcHybridContainer(QWidget *parent = 0, Qt::WFlags flags = 0);
	IdcHybridContainer(const QUrl& url);
	~IdcHybridContainer();

	void setOfflineMode(bool state);
	bool getOfflineMode();
private:
	Ui::IdcHybridContainerClass ui;
    QWebView *view;
	QLineEdit* locationEdit;

public slots:
	void populateJavaScriptWindowObject();
    void openFile();
    void printFile();
    void printPdf();
    void onScan(QString scanData);
	void activateScanner();
	void releaseScanner();
	void onCapture(QString data);
	void offlineBoxToggled(bool checked);
	void changeLocation();

private:
    QString currentFile;
    QTextEdit *editor;
    QTextDocument *document;
	QextSerialPort * _port;
	MyNetworkAccessManager* nwAccessMgr; 
	QCheckBox* offlineBox;
};

#endif // IDCHYBRIDCONTAINER_H
