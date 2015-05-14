/*************************************************************************
	> File Name: Mycondition.cc
	> Author: 周雨晨
	> Mail: 15917836@qq.com
	> Created Time: Thu 14 May 2015 10:57:03 CST
 ************************************************************************/

#include "Mylock.h"
#include "Mycondition.h"
#include <assert.h>
namespace wd
{
    Mycondition::Mycondition(Mylock & mutex):
        m_mutex_(mutex)
    {
        pthread_cond_init(&m_cond_,NULL);
    }

    Mycondition::~Mycondition()
    {
        pthread_cond_destroy(&m_cond_);
    }

    void Mycondition::wait()
    {
        assert(m_mutex_.isLocked());
        pthread_cond_wait(&m_cond_,m_mutex_.getMutexPtr());
    }

    void Mycondition::notify()
    {
        pthread_cond_signal(&m_cond_);
    }

    void Mycondition::broadcast()
    {
        pthread_cond_broadcast(&m_cond_);
    }
}
