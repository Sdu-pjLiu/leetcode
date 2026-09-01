# [](https://leetcode.cn/problems/string-to-integer-atoi/description/)

## Description

Difficulty: **undefined**


## Solution

Language: ****

```
class Solution:
    def myAtoi(self, s: str) -> int:
        _Max = 2**31 - 1
        _Min = -2**31
        sign = 1  # 1表示正数，-1表示负数
        started = False  # 是否已经开始读取数字
        sum_num = 0
        
        for a in s:
            if not started:
                if a == ' ':
                    continue
                elif a == '+':
                    sign = 1
                    started = True
                elif a == '-':
                    sign = -1
```