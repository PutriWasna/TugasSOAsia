#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QString>



class mythread : public QThread
	// mari kita membuat kelas untuk perintah-perintah
		// yang akan dijalankan sebagai thread

{
	public :
		explicit mythread (QString s) ;
		explicit mythread (QString s , int , delay) ;
		
		void run() ;
	
	
	private :
		QString name ;
		int delay ;
}

#endif  // MYTHREAD_H

