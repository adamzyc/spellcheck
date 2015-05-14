/*************************************************************************
	> File Name: MyConf.cc
	> Author: 周雨晨
	> Mail: 15917836@qq.com
	> Created Time: Thu 14 May 2015 11:33:47 CST
 ************************************************************************/

#include "MyConf.h"
namespace wd
{
    MyConf::MyConf(const string& filename) : fin_(filename)
    {
        setup_m_map_();
        set_up_m_vec_();
        set_up_m_index_();
    }

    void MyConf::set_up_m_vec_()
    {
        string line;
        string word;
        string file("dict");
        ifstream inFile(m_map_[file]);
        while(getline(inFile,line))
        {
            std::istringstream record(line);
            while(record >> word)
            {
                word_trans(word);
                int flag = 0;
                for(const auto &w : word_map_)
                {
                    if(word == w.first)
                    {
                        word_map_[word] ++;
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0)
                    word_map_[word] = 1;
            }
        }
        for(const auto &w : word_map_)
        {
            m_vec_.push_back(w);
        }
    }

    void MyConf::setup_m_map_()
    {
        ifstream config("./config.txt");
        string line,key,value;
        while(getline(config,line))
        {
            std::istringstream record(line);
            while(record >> key)
            {
                record >> value;
                if(key == string("ip") || key == string("port")
                        || key == string("dict"))
                {
                    m_map_[key] = value;
                    break;
                }
            }
        }
    }

    void MyConf::set_up_m_index_()
    {
        for(int i=0;i < m_vec_.size();++i)
        {
            for(const auto &c : m_vec_[i].first)
            {
                string w(1,c);
                m_index_[w].insert(i);
            }
        }
    }
    void MyConf::print()
    {
        for(const auto &w : m_map_)
        {
            cout << "key: " << w.first << " value: " << w.second << endl;
        }
        for(const auto &w : word_map_)
        {
            cout << "word: " << w.first << " time: " << w.second << endl;
        }
        for(const auto &w : m_index_)
        {
            cout << "character: " << w.first << endl;
            for(const auto &i : w.second)
            {
                cout << m_vec_[i].first << endl;
            }
        }
    }

}
