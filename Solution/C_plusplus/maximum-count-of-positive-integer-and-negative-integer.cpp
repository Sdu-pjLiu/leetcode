#include <bits/stdc++.h>
using namespace std;

class Solution
{ // 正常循环
 // 可以从中间往两头找
public:
    int maximumCount(vector<int> &nums)
    {
        int len = nums.size();
        int pos = 0, neg = 0;
        for (int i = 0; i < len; i++)
        {
            if (nums[i] > 0)
                pos++;
            if (nums[i] < 0)
                neg++;
        }
        return max(pos,neg);
    }
};