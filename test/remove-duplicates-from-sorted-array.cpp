//
// Created by deepinsight on 2026/1/27.
// Author: Lpj
// Date: 2025-01-27
//

# include <bits/stdc++.h>
using namespace std;

// 去重后计算长度
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int le = 0;
        for (int ri = 0 ; ri< nums.size(); ++ri){
            for (int i = 0 ; i < ri; ++i){
                if (nums[i] == nums[ri]){
                    nums.erase((nums.begin()+ri));
                    ri --;
                    break;
                }
            }
        }
        le = nums.size();
        return le;
    }
};

// 使用双指针，只计算去重后数组的长度
class Solution1 {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int slow = 0;
        for (int fast = 1; fast < nums.size(); ++fast) {
            if (nums[fast] != nums[slow]) {
                slow++;
                nums[slow] = nums[fast];
            }
        }
        return slow + 1; // 返回唯一元素数量
    }
};

int main(){
    Solution1 sol;
    vector<int> nums = {1,2,3,3,3,5};
    cout << sol.removeDuplicates(nums)<< endl;
    return 0;
}