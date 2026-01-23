//
// Created by deepinsight on 2026/1/23.
// Author: lpj
//

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastIndex; // 记录字符上一次出现的位置
        int left = 0; // 窗口左边界（包含）
        int maxLen = 0; // 记录最大无重复子串长度

        for (int right = 0; right < (int) s.size(); ++right) {
            char c = s[right]; // 当前要加入窗口的字符

            // 如果字符 c 之前出现过，尝试更新 left。
            // 注意：我们不能直接把 left 设为 lastIndex[c] + 1，
            // 因为 left 可能已经在更右侧（上一轮已经移动过）。
            // 所以要取 max(left, lastIndex[c] + 1)
            if (lastIndex.count(c)) {
                left = max(left, lastIndex[c] + 1);
            }

            // 更新字符 c 的最新出现位置为当前索引
            lastIndex[c] = right;

            // 当前无重复子串长度为 right - left + 1，更新最大值
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

int main() {
    Solution sol;
    cout << sol.lengthOfLongestSubstring("abcabcbb") << endl; // 输出 3
    cout << sol.lengthOfLongestSubstring("bbbbb") << endl; // 输出 1
    cout << sol.lengthOfLongestSubstring("pwxwkew") << endl; // 输出 3
}
