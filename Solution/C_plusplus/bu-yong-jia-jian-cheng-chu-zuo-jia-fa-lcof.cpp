# include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int encryptionCalculate(int dataA, int dataB) {
        while (dataB != 0) {
            // 计算进位
            int carry = (dataA & dataB) << 1;

            // 不考虑进位的加法
            dataA = dataA ^ dataB;

            // 将进位加入下一轮计算
            dataB = carry;
        }

        return dataA;
    }
};

int main(){
    int a =5;
    int b = -1;
    Solution sol;
    cout << sol.encryptionCalculate(a,b) << endl;
}