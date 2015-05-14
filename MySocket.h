/*************************************************************************
	> File Name: MySocket.h
	> Author: 周雨晨
	> Mail: 15917836@qq.com
	> Created Time: Thu 14 May 2015 17:10:15 CST
 ************************************************************************/

#ifndef _MYSOCKET_H
#define _MYSOCKET_H
#include <string>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include <pthread.h>

namespace wd
{
    class MyConf;
    class MySocket
    {
    public:
        MySocket(MyConf& conf);
        int send_message(void* buf,int len);
        int recv_message(void* buf,int len);
        const struct sockaddr_in getaddr()const;
    private:
        int m_fd_;
        struct sockaddr_in m_addr_;  //服务器端
        socklen_t m_len_;
        MyConf& m_conf_;
    };
}
#endif
