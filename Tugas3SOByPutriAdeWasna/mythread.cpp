#include "mythread.h"
#include <QDebug>

myhread::mythread(QString s)
{
	delay = 10 ;
	this->name = s ;
}


mythread::mythread(QString s , int delay)
{
	this->delay	= delay ;
	this->name	= s ;
}


void mythread::run()
{
	int i = 0 ;
	
	
	while (i <= 20)
	{
		qDebug() << this->name << " " << i ;
		QThread::sleep(this->delay) ;
		i++ ;
	}
}

