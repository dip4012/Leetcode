#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
    int m_size;
    unordered_map<int, list<pair<int, int>>::iterator> m_map;
    list<pair<int, int>> m_list;

public:
    LRUCache(int capacity)
    {
        m_size = capacity;
    }

    int get(int key)
    {
        auto itr = m_map.find(key);
        if (itr == m_map.end())
            return -1;
        m_list.splice(m_list.begin(), m_list, itr->second);
        return itr->second->second;
    }

    void put(int key, int value)
    {
        auto itr = m_map.find(key);
        if (itr != m_map.end())
        {
            m_list.splice(m_list.begin(), m_list, itr->second);
            itr->second->second = value;
            return;
        }
        if (m_map.size() == m_size)
        {
            int del_key = m_list.back().first;
            m_list.pop_back();
            m_map.erase(del_key);
        }
        m_list.emplace_front(key, value);
        m_map[key] = m_list.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */