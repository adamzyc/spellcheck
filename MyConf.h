/*************************************************************************
  > File Name: MyConf.h
  > Author: 周雨晨
  > Mail: 15917836@qq.com
  > Created Time: Thu 14 May 2015 11:11:45 CST
 ************************************************************************/

#ifndef _MYCONF_H
#define _MYCONF_H
#include <map>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <set>
#include <sstream>
using std::pair;
using std::cout;
using std::cin;
using std::map;
using std::string;
using std::vector;
using std::set;
using std::ifstream;
using std::endl;
namespace wd
{
    class MyConf
    {
    public:
        MyConf(const string& filename);
        ~MyConf() = default;
        void index_to_map(int &i,map<string,set<int>> &map);  //将vector[i]
        //中的每个字母放入m_index_映射中
        string& word_trans(string& word)
        {
            int len = word.size();
            for(auto i = 0;i < word.size();++i)
            {
                word[i] = tolower(word[i]);
                if(!isalpha(word[i]))
                {
                    word.erase(i,1);
                    i--;
                }
            }
            return word;
        }
        void setup_m_map_();
        void set_up_m_vec_();
        void set_up_m_index_();
        void print();
    private:
        map<string,string> m_map_;//存放配置文件 配置项--配置
        vector<pair<string,int>> m_vec_;//存放单词和频率word--frequence;
        map<string,set<int>> m_index_;   //一个字母在哪些单词中出现
        map<string,int> word_map_;
        ifstream fin_;
    };
}
#endif
