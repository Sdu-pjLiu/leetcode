#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isLongPressedName(string name, string typed)
    {
        bool res = true;
        bool eq = true;
        int l = 0;
        int r = 0;
        while (res && l <= name.size() && r <= typed.size())
        {
            if (name.size() > typed.size())
            {
                res = false;
            }
            else if (name[0] != typed[0])
            { // 判断初始
                res = false;
            }
            else if (name[l] == typed[r])
            { // 如果相同，左右同时右移, 注意边界，因为typed 肯定要比name长,所以需要注意name的长度
                r++;
                if (l < name.size())
                {
                    l++;
                }
                eq = true;
            }
            else if (name[l] != typed[r] && eq)
            { // 如果不相同，name 左移，判断是否与上一个字母是否相等，eq为False；下一次还是不相等直接返回False
                l--;
                eq = false;
            }
            else if (name[l] != typed[r] && eq == false)
            {
                res = false;
            }
        }
        return res;
    }
};

// 官方详解
class Solution2 {
public:
    bool isLongPressedName(string name, string typed) {

        // i：指向 name 当前需要匹配的字符
        // j：指向 typed 当前正在检查的字符
        //
        // 一开始两个字符串都从第 0 个字符开始比较
        int i = 0;
        int j = 0;

        // j < typed.length()
        //
        // 只要 typed 还有字符没有检查完，就继续循环。
        //
        // 为什么主要看 j？
        // 因为 typed 可能比 name 长，多出来的字符可能是长按产生的。
        while (j < typed.length()) {

            // 情况 1：正常匹配
            //
            // i < name.length()
            //   ↓
            // 防止 i 已经走到 name 的末尾，再访问 name[i] 导致越界。
            //
            // name[i] == typed[j]
            //   ↓
            // 当前 name 的字符和 typed 的字符相同，
            // 说明这是一个正常输入的字符。
            if (i < name.length() && name[i] == typed[j]) {

                // 当前字符已经成功匹配
                // name 和 typed 都向后移动
                i++;
                j++;

            }

            // 情况 2：当前 typed[j] 没有匹配 name[i]
            // 但是它和 typed 前一个字符相同
            //
            // typed[j] == typed[j - 1]
            //   ↓
            // 说明当前这个字符很可能是前一个字符长按产生的。
            //
            // 例如：
            //
            // name  = "alex"
            // typed = "aaleex"
            //          ↑
            //          当前这个 'a' 是多出来的
            //
            // 前一个字符也是 'a'：
            //
            // typed[j]     = 'a'
            // typed[j - 1] = 'a'
            //
            // 所以可以认为这个 'a' 是长按产生的。
            else if (j > 0 && typed[j] == typed[j - 1]) {

                // 这是长按产生的重复字符，
                // 它不需要匹配 name 中的新字符。
                //
                // 所以只移动 typed 的指针 j，
                // i 保持不变。
                j++;

            }

            // 情况 3：既不能正常匹配，
            // 又不是长按产生的重复字符
            //
            // 说明 typed 不可能由 name 长按得到。
            else {

                return false;
            }
        }

        // typed 已经全部检查完了。
        //
        // 最后检查 name 是否也刚好全部匹配完成。
        //
        // i == name.length()
        //   ↓
        // 说明 name 中每一个字符都已经成功匹配。
        //
        // 如果 i < name.length()
        //   ↓
        // 说明 name 还有字符没有出现在 typed 中。
        return i == name.length();
    }
};

int main()
{
    Solution sol;
    string name = "alex";
    string typed = "aaleexa";
    cout << sol.isLongPressedName(name, typed) << endl;
}
