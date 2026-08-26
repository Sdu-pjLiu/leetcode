// 合并两个有序数组
#include <bits/stdc++.h>
using namespace std;
/*
给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。

请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。

注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。
*/
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        // 先删除 nums1 后面预留的 0
        nums1.resize(m);

        // c 表示 nums1 当前查找的位置
        int c = 0;

        for (int j = 0; j < n; j++)
        {
            // 找 nums2[j] 应该插入的位置
            while (c < nums1.size() && nums1[c] <= nums2[j])
            {
                c++;
            }

            // 插入 nums2[j]
            nums1.insert(nums1.begin() + c, nums2[j]);

            // 插入之后，继续从下一个位置寻找
            c++;
        }
    }
};

int main()
{
    Solution sol;
    vector<int> a = {1, 1, 2, 3, 4, 0, 0};
    vector<int> b = {2, 3};
    sol.merge(a, 5, b, 2);
    for (int i = 0; i < 7; i++)
    {
        cout << a[i] << endl;
    }
}