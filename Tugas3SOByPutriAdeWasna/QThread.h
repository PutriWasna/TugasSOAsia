#ifndef QTHREAD_H
#define QTHREAD_H

#if defined(QT_THREAD_SUPPORT)

#ifndef QT_H
#include "qwindowdefs.h"
#ifndef QT_NO_COMPAT
#include "qmutex.h"
#include "qsemaphore.h"
#include "qwaitcondition.h"
#endif // QT_NO_COMPAT
#endif // QT_H

#include <limits.h>

class QThreadInstance;

class Q_EXPORT QThread : public Qt
{
public:
    static Qt::HANDLE currentThread();

#ifndef QT_NO_COMPAT
    static void postEvent( QObject *,QEvent * );
#endif

    static void initialize();
    static void cleanup();

    static void exit();

#ifdef Q_QDOC
    QThread( unsigned int stackSize = 0 );
#else
    QThread( unsigned int stackSize );
    QThread();
#endif

    virtual ~QThread();

    // default argument causes thread to block indefinately
    bool wait( unsigned long time = ULONG_MAX );

    enum Priority {
	IdlePriority,

	LowestPriority,
	LowPriority,
	NormalPriority,
	HighPriority,
	HighestPriority,

	TimeCriticalPriority,

	InheritPriority
    };

#ifdef Q_QDOC
    void start( Priority = InheritPriority );
#else
    void start( Priority );
    void start();
#endif

    void terminate();

    bool finished() const;
    bool running() const;

protected:
    virtual void run() = 0;

    static void sleep( unsigned long );
    static void msleep( unsigned long );
    static void usleep( unsigned long );

private:
    QThreadInstance * d;
    friend class QThreadInstance;

#if defined(Q_DISABLE_COPY)
    QThread( const QThread & );
    QThread &operator=( const QThread & );
#endif // Q_DISABLE_COPY
};

#endif // QT_THREAD_SUPPORT

#endif // QTHREAD_H

