#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int res = 0;
        int len = chalk.size();
        long long int sum = 0;
        for(int i =0;i<len;i++){
            sum+= chalk[i];
        }
        k = k % sum;

        // 单纯下面这个循环会超时，有一个案例无法通过，超时，只能预处理
        while (true){
            for(int i = 0;i< len; i++){
                if(k<chalk[i]){
                    return i;
                }else{
                    k = k - chalk[i];
                }
            }
        }
    }
};


int main(){
    Solution sol;
    vector<int> chalk = {5,1,5};
    int k = 22;
    cout << sol.chalkReplacer(chalk,k) <<endl;
}