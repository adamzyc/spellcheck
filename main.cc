/*************************************************************************
	> File Name: main.cc
	> Author: 周雨晨
	> Mail: 15917836@qq.com
	> Created Time: Thu 14 May 2015 15:07:58 CST
 ************************************************************************/

#include <iostream>
#include "MyConf.h"
int main()
{
    wd::MyConf test1("./The_Holy_Bible.txt");
    test1.print();
    return 0;
}
