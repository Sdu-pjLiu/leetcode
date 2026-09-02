# include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        for(int i =0;i<2;i++){
            for(int j = 0;j<2;j++){
                int num_b = 0;
                int num_w = 0;

                if(grid[i][j] == 'B'){
                    num_b ++;
                }else if(grid[i][j] == 'W'){
                    num_w ++;
                }
                
                if(grid[i+1][j] == 'B'){
                    num_b ++;
                }else if(grid[i+1][j] == 'W'){
                    num_w ++;
                }
                
                if(grid[i][j+1] == 'B'){
                    num_b ++;
                }else if(grid[i][j+1] == 'W'){
                    num_w ++;
                }
                
                if(grid[i+1][j+1] == 'B'){
                    num_b ++;
                }else if(grid[i+1][j+1] == 'W'){
                    num_w ++;
                }
                
                if(num_b >=3 || num_w >=3){
                    return true;
                }
            }
        }
        return false;
    }
};