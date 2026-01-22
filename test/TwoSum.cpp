#include <bits/stdc++.h>
using namespace std;

// Solution 1 ; The time complexity of program is O(n^2)
class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        // 没找到时返回空结果，避免未定义行为
        return {};
    }
};

// Solution 2 ; The time complexity of program is O(n)
class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map; // 存储值 -> 下标
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (map.find(complement) != map.end()) {
                return {map[complement], i};
            }
            map[nums[i]] = i;
        }
        return {}; // 理论上不会执行到这里
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> res = s.twoSum(nums, target);
    for (int x : res) cout << x << " ";
    return 0;
}
