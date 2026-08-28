//
// Created by deepinsight on 2026/1/28.
// Author: Lpj
// Date: 2026-01-28
//

# include <bits/stdc++.h>
using namespace std;

// 最简单的逻辑，但是会超时，所以需要进行调整逻辑,时间复杂度O(n^2)
class Solution0 {
public:
    long long countPairs(vector<int>& nums, int k) {
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j ){
                long long res = (long long)nums[i] * nums[j] ;
                if (res % k == 0 ){
                    ++count;
                }
            }
        }
        return count;
    }
};

// From Chatgpt
// a和b是否能够被k整除<=>判断(a和k的最大公约数) * (b和k的最大公约数)是否能否被k整除
// 个人理解：gcd(nums[i],k)作为key，出现次数作为value;组成哈希表；每次来一个新的数，就遍历之前的gcd的值，然后如果有能整除的，就在统计次数上+匹配的gcd出现的次数
//
class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        // 用哈希表记录每个 gcd(nums[i], k) 出现的次数
        unordered_map<int, long long> cnt;
        long long ans = 0;

        for (int a : nums) {
            int g = gcd(a, k);  // 求出 a 与 k 的最大公约数

            // 遍历之前所有的 gcd 值，看看能否与当前这个配对
            for (auto [g2, c] : cnt) {
                // 如果 g * g2 可以被 k 整除，说明 (a, 前面那些数) 都可以组成合法对
                if ((1LL * g * g2) % k == 0)
                    ans += c;  // 加上这些配对的数量
            }

            // 统计当前 gcd 出现次数
            cnt[g]++;
        }

        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,2,3,4,5};
    int k = 2;
    cout << sol.countPairs(nums,k) << endl;
    return 0;
}