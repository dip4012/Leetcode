#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> wordSet;
        bool present = false;
        for (string word : wordList)
        {
            if (word.compare(endWord) == 0)
                present = true;

            wordSet.insert(word);
        }

        if (!present)
            return 0;

        queue<string> q;
        q.push(beginWord);

        int depth = 0;

        while (!q.empty())
        {
            depth++;
            int levelSize = q.size();

            while (levelSize--)
            {
                string cur = q.front();
                q.pop();

                for (int i = 0; i < cur.length(); i++)
                {
                    string temp = cur;
                    for (char c = 'a'; c <= 'z'; c++)
                    {
                        temp[i] = c;

                        if (temp.compare(endWord) == 0)
                            return depth + 1;

                        if (wordSet.find(temp) != wordSet.end())
                        {
                            q.push(temp);
                            wordSet.erase(temp);
                        }
                    }
                }
            }
        }

        return 0;
    }
};