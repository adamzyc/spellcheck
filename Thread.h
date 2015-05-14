/*************************************************************************
	> File Name: Thread.h
	> Author: 周雨晨
	> Mail: 15917836@qq.com
	> Created Time: Thu 14 May 2015 19:25:02 CST
 ************************************************************************/

#ifndef _THREAD_H
#define _THREAD_H
#include <pthread.h>
#include <iostream>
#include <vector>
#include <functional>
namespace wd
{
    class ThreadPool;
    class Thread
    {
    public:
        void thread_start();
        static void* runInThread(void* arg);
        void run();
    private:
        bool m_on_;
        pthread_t m_pid_;
        pthread_attr_t m_attr_;
        ThreadPool* m_pool_;
    };
}
#endif
