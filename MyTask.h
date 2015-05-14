/*************************************************************************
	> File Name: MyTask.h
	> Author: 周雨晨
	> Mail: 15917836@qq.com
	> Created Time: Thu 14 May 2015 20:34:36 CST
 ************************************************************************/

#ifndef _MYTASK_H
#define _MYTASK_H
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <netinet/in.h>
using std::vector;
using std::queue;
using std::map;
using std::string;
using std::set;
using std::pair;

namespace wd
{
    class MyConf;
    class MyResult;
    class MyTask
    {
    public:
        MyTask(MyConf& conf);
        void satistic(set<int>& iset);
        int editdistance(const string& right);
        void get_result();
    private:
        string m_express_;
        struct sockaddr_in m_addr_;
        int m_fd_;
        vector<pair<string,int>>* m_vec_;
        map<string,set<int>>* m_index_;
    };
}
#endif
