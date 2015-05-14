/*************************************************************************
	> File Name: Mycondition.h
	> Author: 周雨晨
	> Mail: 15917836@qq.com
	> Created Time: Thu 14 May 2015 10:50:40 CST
 ************************************************************************/

#ifndef _MYCONDITION_H
#define _MYCONDITION_H
#include <pthread.h>

namespace wd
{
    class Mylock;
    class Mycondition
    {
    public:
        Mycondition(Mylock& mutex);
        ~Mycondition();

        void wait();
        void broadcast();
        void notify();
    private:
        Mylock &m_mutex_;
        pthread_cond_t m_cond_;
    };
}
#endif
