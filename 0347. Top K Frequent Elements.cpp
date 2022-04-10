#include <bits/stdc++.h>
using namespace std;

class Solution
{
    map<int, int> count_map;
    vector<int> unique;

    int partition(int left, int right, int pivot_index)
    {
        int pivot_frequency = count_map[unique[pivot_index]];
        swap(unique[pivot_index], unique[right]);

        int store_index = left;
        for (int i = left; i <= right; i++)
        {
            if (count_map[unique[i]] < pivot_frequency)
            {
                swap(unique[store_index], unique[i]);
                store_index++;
            }
        }

        swap(unique[store_index], unique[right]);
        return store_index;
    }

    void quickSelect(int left, int right, int k_smallest)
    {
        if (left == right)
            return;

        int pivot_index = left + rand() % (right - left + 1);
        pivot_index = partition(left, right, pivot_index);

        if (pivot_index + 1 == k_smallest)
            return;
        else if (pivot_index + 1 > k_smallest)
            quickSelect(left, pivot_index - 1, k_smallest);
        else
            quickSelect(pivot_index + 1, right, k_smallest);
    }

public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        for (int n : nums)
            count_map[n]++;

        for (auto x : count_map)
            unique.push_back(x.first);

        int n = unique.size();
        if (n == k)
            return unique;

        quickSelect(0, n - 1, n - k);

        vector<int> top_k_frequent(k);
        copy(unique.begin() + n - k, unique.end(), top_k_frequent.begin());
        return top_k_frequent;
    }
};