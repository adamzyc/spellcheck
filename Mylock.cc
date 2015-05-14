/*************************************************************************
	> File Name: Mylock.cc
	> Author: 周雨晨
	> Mail: 15917836@qq.com
	> Created Time: Thu 14 May 2015 10:36:02 CST
 ************************************************************************/

#include "Mylock.h"
namespace wd
{
    Mylock::Mylock():
        isLocking_(false)
    {
        pthread_mutex_init(&m_mutex_,NULL);
    }

    Mylock::~Mylock()
    {
        pthread_mutex_destroy(&m_mutex_);
    }

    void Mylock::lock()
    {
        isLocking_ = true;
        pthread_mutex_lock(&m_mutex_);
    }

    void Mylock::unlock()
    {
        pthread_mutex_unlock(&m_mutex_);
        isLocking_ = false;
    }

    pthread_mutex_t* Mylock::getMutexPtr()
    {
        return &m_mutex_;
    }

    void Mylock::restoreMutexStatus()
    {
        isLocking_ = true;
    }
}
