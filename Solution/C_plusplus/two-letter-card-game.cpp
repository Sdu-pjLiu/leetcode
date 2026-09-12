#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int score(vector<string>& cards, char x) {
        vector<string> ax;  // [0] != x, [1] == x
        vector<string> xa;  // [0] == x, [1] != x
        vector<string> xx;  // [0] == x. [1] == x
        int len = cards.size();
        for(int i = 0;i<len;i++){
            if(cards[i][0] == x && cards[i][1] != x){ // [0]= x , [1] != x
                xa.push_back(cards[i]);
            }
            if(cards[i][1] == x && cards[i][0] != x){ // [0] != x, [1] == x
                ax.push_back(cards[i]); 
            }
            if(cards[i][1] == x && cards[i][0] == x){ // [0] == x, [1] == x
                xx.push_back(cards[i]); 
            }
        }
        int len_ax = ax.size();
        int len_xa = xa.size();
        int len_xx = xx.size();
        int res = 0;
        res = (len_ax / 2) + (len_xa / 2) +  max (len_ax%2+len_xa%2,len_xx);
        return res;
    }
};

int main(){
    Solution sol;
    vector<string> cards={"aa","ab","ba"};
    char x = 'a';
    cout << sol.score(cards,x)<< endl;
}