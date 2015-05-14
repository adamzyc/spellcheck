/*************************************************************************
	> File Name: Noncopyable.h
	> Author: 周雨晨
	> Mail: 15917836@qq.com
	> Created Time: Thu 14 May 2015 10:06:37 CST
 ************************************************************************/

#ifndef _NONCOPYABLE_H
#define _NONCOPYABLE_H
class Noncopyable
{
public:
    Noncopyable() = default;
    ~Noncopyable() = default;
private:
    Noncopyable(const Noncopyable &);
    Noncopyable& operator=(const Noncopyable &);
};
#endif
