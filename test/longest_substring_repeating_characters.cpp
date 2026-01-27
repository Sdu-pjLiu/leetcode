//
// Created by deepinsight on 2026/1/23.
// Author: lpj
//

#include <bits/stdc++.h>
using namespace std;

// 暴力解决，时间复杂度O(n^2)
class Solution1 {
public:
    int lengthOfLongestSubstring(string s) {
        int max_len = 0; // 记录最大长度
        string aw; // 初始化需要检查的子串
        for (int right = 0 ;right < s.size(); ++right){
            char c = s[right];
            for(int i = 0; i < aw.size(); ++i){
                if(s[right] == aw[i]){ 
                    aw = aw.substr(i + 1); 
                    break; 
                }
            }
            aw.push_back(c);
            max_len = max(max_len,(int)aw.size());
        }
        return max_len;
    }
};

// 时间复杂度O(n)
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
    Solution1 sol;
    cout << sol.lengthOfLongestSubstring("abcabcbb") << endl; // 输出 3
    cout << sol.lengthOfLongestSubstring("bbbbb") << endl; // 输出 1
    cout << sol.lengthOfLongestSubstring("pwxwkew") << endl; // 输出 3
}
