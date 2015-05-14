/*************************************************************************
	> File Name: Mylock.h
	> Author: 周雨晨
	> Mail: 15917836@qq.com
	> Created Time: Thu 14 May 2015 10:27:24 CST
 ************************************************************************/

#ifndef _MYLOCK_H
#define _MYLOCK_H
#include <pthread.h>
namespace wd
{
    class Mylock
    {
    public:
        Mylock();
        ~Mylock();

        void lock();
        void unlock();
        bool isLocked();
        pthread_mutex_t* getMutexPtr();
        void restoreMutexStatus();
    private:
        pthread_mutex_t m_mutex_;
        bool isLocking_;
    };

    class MylockGuard
    {
    public:
        MylockGuard(Mylock &mutex):
            m_mutex_(mutex)
        {
            m_mutex_.lock();
        }
        ~MylockGuard()
        {
            m_mutex_.unlock();
        }
    private:
            Mylock m_mutex_;
    };
}
#endif
