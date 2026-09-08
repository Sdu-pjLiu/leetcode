#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();

        // dp[i] 表示到达第 i 个台阶顶部时的最小花费
        // 注意：第 n 个位置就是楼梯顶部
        vector<int> dp(n + 1, 0);

        // 可以从下标 0 或 1 开始，因此：
        // dp[0] = 0
        // dp[1] = 0

        for (int i = 2; i <= n; i++)
        {
            // 到达 i 有两种方法：
            // 1. 从 i-1 走一步过来，需要支付 cost[i-1]
            // 2. 从 i-2 走两步过来，需要支付 cost[i-2]
            dp[i] = min(
                dp[i - 1] + cost[i - 1],
                dp[i - 2] + cost[i - 2]);
        }

        return dp[n];
    }
};

int main()
{

    vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    Solution sol;

    cout << sol.minCostClimbingStairs(cost) << endl;
}