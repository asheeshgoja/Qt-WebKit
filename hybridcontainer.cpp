#include "stdafx.h"
#include "idchybridcontainer.h"
#include <QtGui>
#include <QtWebKit>

#include <QtNetwork/qsslerror.h>
#include <QtNetwork/QSslConfiguration>
#include <QtNetwork/QSslSocket>

#include "SerialPort\qextserialport.h"
#include "SerialPort\PortListener.h"
#include "mynetworkaccessmanager.h" 

IdcHybridContainer::IdcHybridContainer(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);  
}


void IdcHybridContainer::changeLocation()
{
    QUrl url = QUrl(locationEdit->text());
    view->load(url);
    view->setFocus();
}


IdcHybridContainer::IdcHybridContainer(const QUrl& url)
{

	this->setWindowTitle("UPS Smart Web Container");
    
	view = new QWebView(this);

	//nav bar
	offlineBox = new QCheckBox(this);
	offlineBox->setText("Offline Mode");

    connect(offlineBox, SIGNAL( toggled(bool)), SLOT( offlineBoxToggled(bool) ));

    locationEdit = new QLineEdit(this);
    locationEdit->setSizePolicy(QSizePolicy::Expanding, locationEdit->sizePolicy().verticalPolicy());
    connect(locationEdit, SIGNAL(returnPressed()), SLOT(changeLocation()));

	QToolBar *toolBar = addToolBar(tr("Navigation"));
    toolBar->addWidget(offlineBox);
    toolBar->addAction(view->pageAction(QWebPage::Back));
    toolBar->addAction(view->pageAction(QWebPage::Forward));
    toolBar->addAction(view->pageAction(QWebPage::Reload));
    toolBar->addAction(view->pageAction(QWebPage::Stop));
    toolBar->addWidget(locationEdit);

	this->resize(1400,800);
	view->move(0,30);

    QWebSettings::globalSettings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);
    QWebSettings::globalSettings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);
	QNetworkProxyFactory::setUseSystemConfiguration(true);


	//MyNetworkAccessManager
	nwAccessMgr = new MyNetworkAccessManager(this);
	view->page()->setNetworkAccessManager(nwAccessMgr);


	view->resize(1400,800);

	connect(view->page()->mainFrame(), SIGNAL(javaScriptWindowObjectCleared()),
            this, SLOT(populateJavaScriptWindowObject()));

    view->settings()->setAttribute(QWebSettings::LocalContentCanAccessRemoteUrls,true);
    view->load(url);





    editor = new QTextEdit(this);
    document = new QTextDocument(this);
    editor->setDocument(document);
	editor->hide();

	_port = NULL;
}

IdcHybridContainer::~IdcHybridContainer(){}

void IdcHybridContainer::offlineBoxToggled(bool checked)
{
	setOfflineMode(checked);
}

void IdcHybridContainer::setOfflineMode(bool state)
{
	offlineBox->setChecked(state);
	nwAccessMgr->setOfflineMode(state);
	if(state == false)
		nwAccessMgr->rePostRequestsToServer();
}

bool IdcHybridContainer::getOfflineMode()
{
	return offlineBox->checkState() == Qt::CheckState::Checked ? true:false;
}

void IdcHybridContainer::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open file"), currentFile, "HTML files (*.html);;Text files (*.txt)");
    
    if (!fileName.isEmpty()) {
        QFileInfo info(fileName);
        if (info.completeSuffix() == "html") {
            QFile file(fileName);
            
            if (file.open(QIODevice::ReadOnly)) {
                editor->setHtml(file.readAll());
                file.close();
                currentFile = fileName;
            }
        } else if (info.completeSuffix() == "txt") {
            QFile file(fileName);
            
            if (file.open(QIODevice::ReadOnly)) {
                editor->setPlainText(file.readAll());
                file.close();
                currentFile = fileName;
            }
        }
    }

	QWebFrame *frame = view->page()->mainFrame();
//	QWebFrame* frame = view->page()->currentFrame(); 
	QWebElement document = frame->documentElement();

	QWebElement contentsElm = frame->findFirstElement("#contents");
	contentsElm.setPlainText(editor->document()->toPlainText());
	/*
	QWebElement data = document.findFirst("input[id=data]");
	data.evaluateJavaScript("this.value = '768686' ;");*/

}

void IdcHybridContainer::printFile()
{

    QTextDocument *document = editor->document();
    QPrinter printer;

   // QPrintDialog *printDialog = new QPrintDialog(&printer, this);
	//printDialog->show();
	//printDialog->hide();   
	
	//if (printDialog->exec() != QDialog::Accepted)
     //   return;

    document->print(&printer);

}

void IdcHybridContainer::onScan(QString scanData)
{
	QWebFrame* frame = view->page()->currentFrame(); 
 //   QWebElement document = frame->documentElement();
	//QWebElement data = document.findFirst("input[id=data]");
	//data.evaluateJavaScript("this.value = '" + scanData + "' ;");

    //QMessageBox::information(this,"IdcHybridContainer","Tracking ID = " + scanData ,NULL);


	QWebElement elm = frame->findFirstElement("#MessageBar");
	//elm.setPlainText(scanData);
	elm.evaluateJavaScript("this.innerHtml = 'UDC Data Capture-QT-INJECTED:" + scanData + "' ;");



}

void IdcHybridContainer::printPdf()
{
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);

    QPrintDialog *printDialog = new QPrintDialog(&printer, this);
	printDialog->show();
	printDialog->hide();
    //if (printDialog->exec() == QDialog::Accepted)
    editor->document()->print(&printer);
}



//void IdcHybridContainer::openFile()
//{
//	QWebFrame *frame = view->page()->mainFrame();
//    QWebElement contentsElm = frame->findFirstElement("#contents");
//    QString contents = contentsElm.evaluateJavaScript("this.value").toString();
//    QMessageBox::information(this,"IdcHybridContainer","contents = " + contents ,NULL);
//}
//
//void IdcHybridContainer::printFile()
//{
//	QWebFrame *frame = view->page()->mainFrame();
//    QWebElement contentsElm = frame->findFirstElement("#contents");
//    QString contents = contentsElm.evaluateJavaScript("this.value").toString();
//    QMessageBox::information(this,"IdcHybridContainer","contents = " + contents ,NULL);
//}

void IdcHybridContainer::populateJavaScriptWindowObject()
{
    view->page()->mainFrame()->addToJavaScriptWindowObject("UpsIdcJavaScriptExtension", this);
}


void IdcHybridContainer::releaseScanner()
{
	if( _port == NULL) return;

	_port->close();
	delete _port;
	_port = NULL;

	QWebFrame *frame = view->page()->mainFrame();
	QWebElement contentsElm = frame->findFirstElement("#ScannerStatus");
	contentsElm.setPlainText("Scanner Inactive");
	contentsElm.setStyleProperty("color", "white");
	contentsElm.setStyleProperty("background-color", "red");

}
	
void IdcHybridContainer::activateScanner()
{
	QWebFrame *frame = view->page()->mainFrame();
	QWebElement contentsElm = frame->findFirstElement("#ScannerStatus");

	if( _port != NULL) return;

	_port = new QextSerialPort("COM1", QextSerialPort::EventDriven);

	_port->setBaudRate(BAUD9600);
	_port->setFlowControl(FLOW_XONXOFF);
	_port->setParity(PAR_EVEN);
	_port->setDataBits(DATA_7);
	_port->setStopBits(STOP_1);
	bool retVal = _port->open(QIODevice::ReadWrite);

	if(retVal == false )
	{
		contentsElm.setPlainText("Failed to activate scanner");
		contentsElm.setStyleProperty("color", "white");
		contentsElm.setStyleProperty("background-color", "red");
		delete _port;
		_port = NULL;
		return;
	}

	if (!(_port->lineStatus() & LS_DSR)) {
		//out << "warning: device is not turned on" << endl;
	}

	PortListener * listener = new PortListener(_port);
	//Because port and listener are working in different threads 
	//Qt will choose queued connection. This may produce clusters of 
	//signals waiting in the queue.
	listener->connect(_port, SIGNAL(readyRead()), listener, SLOT(receive()));
	listener->connect(_port, SIGNAL(bytesWritten(qint64)), listener, SLOT(reportWritten(qint64)));
	listener->connect(_port, SIGNAL(aboutToClose()), listener, SLOT(reportClose()));
	listener->connect(_port, SIGNAL(dsrChanged(bool)), listener, SLOT(reportDsr(bool)));


	QObject::connect(	listener,	SIGNAL(dataCaptured(QString)), this,		SLOT(onCapture(QString)));


	
	contentsElm.setPlainText("Scanner Active");
	contentsElm.setStyleProperty("color", "white");
	contentsElm.setStyleProperty("background-color", "green");

}

void IdcHybridContainer::onCapture(QString data)
{
	QWebFrame *frame = view->page()->mainFrame();
	QWebElement contentsElm = frame->findFirstElement("#contents");
	contentsElm.setPlainText(data);

    editor->setPlainText(data);

	//QMessageBox::information(NULL,"IdcHybridContainer","Scan Data ID = " + data ,NULL);
}