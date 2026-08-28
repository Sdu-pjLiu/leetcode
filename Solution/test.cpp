// TEST file
// Created by deepinsight on 2026/1/23.
// Author lpj
//

# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char , int> last_index;
        int left = 0, max_length = 0;
        for (int right = 0; right < s.length(); ++right) {
            char c = s[right];
            if (last_index.count(c)) {

            }
        }
    }
};
