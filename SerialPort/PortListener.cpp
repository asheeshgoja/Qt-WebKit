/**
 * @file PortListener.cpp
 * @brief PortListener Implementation.
 * @see PortListener.h
 */


/*
==============
<INIT>
==============
*/

#include "stdafx.h"

#include <QTextStream>
#include "qextserialport.h"
#include "PortListener.h"


PortListener::PortListener(QextSerialPort * port, QObject * parent):
	QObject(parent)
{
	this->port = port;
}



void PortListener::receive()
{

	QByteArray buffer = port->readAll();
	if(buffer.size() == 0) return;


	QString data = "";

	for(int i=0;i<buffer.size() ;i++) 
		data = data + (char)buffer[i];
	
	
	Sleep(1000);
	emit dataCaptured(data);
	//QTextStream stream;
	//stream << buffer;


	//char data[1024];
	//QTextStream out(stdout);
	//
	//out << "data received: ";
	//int bytesRead = port->read(data, 1024);
	//data[bytesRead] = '\0';
	//out << data << " (" << bytesRead << " bytes)" << endl;
}

void PortListener::reportWritten(qint64 bytes)
{
	/*QTextStream out(stdout);
	
	out << bytes << " bytes written" << endl;*/
}

void PortListener::reportClose()
{
	/*QTextStream out(stdout);
	
	out << "closing port" << endl;*/	
}

void PortListener::reportDsr(bool status)
{
	//QTextStream out(stdout);
	//
	//if (status)
	//	out << "device was turned on" << endl;
	//else
	//	out << "device was turned off" << endl;
}
