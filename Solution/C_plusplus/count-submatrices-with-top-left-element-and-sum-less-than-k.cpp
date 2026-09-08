# include<bits/stdc++.h>
using namespace std;
//  下面这个方法通过测试用例855/859 ,4个超出时间限制
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int hi = grid.size();
        int le = grid[0].size();
        int res = 0;
        for(int i =0;i< hi;i++){
            for(int j = 0;j< le; j++){
                if(is_xiaoyu_k(grid,k,j,i)){
                    res ++;
                }
                else{
                    break;
                }
            }
        }
        return res;
    }
    bool is_xiaoyu_k(vector<vector<int>>& grid, int k, int len, int high){
        //计算长len, 高high的grid的数组是否<k
        int sum = 0;
        for(int i = 0; i <= high;i++){
            for(int j = 0; j <= len; j++){
                sum += grid[i][j];
            }
        }
        if(sum <= k){
            return true;
        }else{
            return false;
        }
    }
};


// 作者：力扣官方题解
// 链接：https://leetcode.cn/problems/count-submatrices-with-top-left-element-and-sum-less-than-k/solutions/3920188/yuan-su-he-xiao-yu-deng-yu-k-de-zi-ju-zh-5ry4/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
class Solution1 {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<int> cols(m);
        int res = 0;
        for (int i = 0; i < n; i++) {
            int rows = 0;
            for (int j = 0; j < m; j++) {
                cols[j] += grid[i][j];
                rows += cols[j];
                if (rows <= k) {
                    res++;
                }
            }
        }
        return res;
    }
};


// 优秀解题方法
class Solution3 {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid[0].size();
        int ans = 0;
        vector<int> col_s(n);
        for (const auto& row : grid) {
            int s = 0;
            for (int j = 0; j < n; ++j) {
                col_s[j] += row[j];
                s += col_s[j];
                if (s > k) {
                    break;
                }

                ++ans;
            }
        }

        return ans;
    }
};
