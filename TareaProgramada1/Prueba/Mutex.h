#ifndef MUTEX_H
#define MUTEX_H
#include <pthread.h>


class Mutex {
public:
   Mutex();
   ~Mutex();
   int Lock();
   int TryLock();
   int Unlock();

private:
   pthread_mutex_t * mutex;

};

#endif // MUTEX_H
