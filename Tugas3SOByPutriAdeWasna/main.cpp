#include <QCoreApplication>
#include <QDebug>
#include "mythread.h"

int main (int argc , char *argv[])
{
	QCoreApplication a (argc , argv) ;
	mythread antrian1 ("antrian 1" , 5) ;     // membuat objek antrian 1 ..
	mythread antrian1 ("antrian 2" , 15)     ,     antrian3 ("antrian 3") ;       // antrian 3 dengan default delay (10 ms)
	
	antrian1.start() ;
	antrian2.start() ;
	antrian3.start() ;
	
	
	return a.exec() ;
}

