#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string greatestLetter(string s)
    {
        char res = 0;

        for (int i = 0; i < s.size(); i++)
        {

            // 只处理大写字母
            if (s[i] >= 'A' && s[i] <= 'Z')
            {

                // 对应的小写字母
                char lower = s[i] - 'A' + 'a';

                // 在字符串中寻找对应的小写字母
                if (s.find(lower) != string::npos)
                {

                    // 当前字母比之前找到的字母更靠后
                    if (s[i] > res)
                    {
                        res = s[i];
                    }
                }
            }
        }

        // 没找到
        if (res == 0)
        {
            return "";
        }

        return string(1, res);
    }
};