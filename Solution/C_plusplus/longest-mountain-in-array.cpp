#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int res = 0;
        int len = arr.size();
        int max_arr_len = 0;
        if(len < 3){
            return 0;
        }
        else if(len >=3){
            for (int i = 1 ;i<len-1 ;i++){
                if(arr[i]>arr[i-1] && arr[i]>arr[i+1])
                    res = max(res,max_ri(arr,i)+max_le(arr,i)+1);
            }
        }
        return res;
    }
    int max_ri(vector<int>& abc, int a){
        int max_len = 0;
        while(a<abc.size()-1 && abc[a]>abc[a+1]){
            max_len ++;
            a++;
        }
        return max_len;
    }
    int max_le(vector<int>& abc, int a){
        int max_len = 0;
        while(a>0&&abc[a]>abc[a-1]){
            max_len ++;
            a--;
        }
        return max_len;
    }
};

int main(){

    vector<int> arr = {2,1,4,7,3,2,5};
    Solution sol;
    cout<< sol.longestMountain(arr)<< endl;

}