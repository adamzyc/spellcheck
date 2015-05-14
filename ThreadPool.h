/*************************************************************************
	> File Name: ThreadPool.h
	> Author: 周雨晨
	> Mail: 15917836@qq.com
	> Created Time: Thu 14 May 2015 20:02:38 CST
 ************************************************************************/

#ifndef _THREADPOOL_H
#define _THREADPOOL_H
#include "Noncopyable.h"
#include <queue>
#include <vector>
#include <functional>
#include <pthread.h>
using std::vector;
using std::queue;
namespace wd
{
    class Thread;
    class MyConf;
    class Mylock;
    class Mycond;
    class MyTask;
    class ThreadPool : Noncopyable
    {
    public:
        ThreadPool(MyConf&);
        ~ThreadPool();

        void pool_start();
        void pool_stop();
        void addTask();
        void runInThread();
    private:
        bool m_isStarting_;
        MyConf& m_myconf_;
        queue<MyTask> m_tasks_;
        Mylock& m_lock_;
        Mycond& m_cond_;
        size_t m_threadsNum_ = 5;
    };
}
#endif
