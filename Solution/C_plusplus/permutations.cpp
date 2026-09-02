# include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 保存所有最终生成的全排列
    vector<vector<int>> ans;

    // dfs(nums, index)：
    // nums[0 ~ index-1] 已经确定
    // 当前要决定 nums[index] 这个位置放哪个数字
    void dfs(vector<int>& nums, int index) {

        // index == nums.size()：
        // 说明 nums 中所有位置都已经确定
        // 此时 nums 就是一个完整的排列
        if (index == nums.size()) {
            ans.push_back(nums);
            return;
        }

        // 从 index 开始，依次选择一个数字放到 index 位置
        //
        // 例如 nums = [1,2,3]，index = 0：
        // i = 0：让 1 放第 0 位
        // i = 1：让 2 放第 0 位
        // i = 2：让 3 放第 0 位
        for (int i = index; i < nums.size(); i++) {

            // 【做选择】
            // 把 nums[i] 交换到 index 位置
            // 相当于确定：当前位置 index 选择 nums[i]
            swap(nums[index], nums[i]);

            // 【递归】
            // 当前 index 位置已经确定
            // 接下来继续确定 index + 1 位置
            dfs(nums, index + 1);

            // 【撤销选择 / 恢复现场】
            // 上面的递归结束后，需要把数组恢复到交换之前的状态
            // 这样下一次循环才能尝试其他数字放在 index 位置
            swap(nums[index], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        // 从第 0 个位置开始决定每个位置应该放哪个数字
        dfs(nums, 0);

        // 返回所有排列
        return ans;
    }
};