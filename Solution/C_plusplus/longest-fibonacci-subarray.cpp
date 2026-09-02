#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    { // 从左到右遍历
        int ans = 2;
        int len = nums.size();
        for (int i = 0; i < len - 2; i++)
        {
            for (int j = i + 2; j < len; j++)
            {
                if (nums[j] == nums[j - 1] + nums[j - 2])
                {
                    ans = max(ans, j - i + 1);
                    continue;
                }
                else
                {
                    break;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> a = {1, 1, 1, 1, 2, 3, 5, 1};
    cout << sol.longestSubarray(a) << endl;
}