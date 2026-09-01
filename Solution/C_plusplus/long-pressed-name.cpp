#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int name_len= name.size();
        int typed_len = typed.size();
        int name_l,typed_l= 0;
        int name_r,typed_r = 1;
        bool res = true;
        if (typed_len<name_len){
            return false;
        }
        while(res){
            int num = 0;
            if(typed[typed_l]!=name[name_l]){
                res = false;
            }
            // 从第一个字母开始，计算typed和named相同字母的长度
            // 如果typed的相同字母的长度>= named
            // typed_l和name_l跳转到下一个字母
            // 否则返回false
        }
    }
};