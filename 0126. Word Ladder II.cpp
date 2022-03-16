#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end())
            return {};
        vector<vector<string>> ans;
        queue<vector<string>> paths;
        paths.push({beginWord});
        int level = 1;
        int minLevel = INT_MAX;

        unordered_set<string> visited;
        while (!paths.empty())
        {
            vector<string> path = paths.front();
            paths.pop();
            if (path.size() > level)
            {
                for (string w : visited)
                    wordSet.erase(w);

                if (path.size() > minLevel)
                    break;
                else
                    level = path.size();
            }

            string last = path.back();
            for (int i = 0; i < last.size(); i++)
            {
                string cur = last;
                for (char c = 'a'; c <= 'z'; ++c)
                {
                    cur[i] = c;
                    if (wordSet.find(cur) != wordSet.end())
                    {
                        vector<string> newPath = path;
                        newPath.push_back(cur);
                        visited.insert(cur);
                        if (cur == endWord)
                        {
                            minLevel = level;
                            ans.push_back(newPath);
                        }
                        else
                        {
                            paths.push(newPath);
                        }
                    }
                }
            }
        }

        return ans;
    }
};