#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int high = grid.size();
        int len = grid[0].size();
        int res = 0;
        for (int i = 0; i < high; i++)
        {
            for (int j = 0; j < len; j++)
            {
                if (grid[i][j] == 1)
                {
                    res = max(res, dfs(grid, i, j, high, len));
                }
            }
        }
        return res;
    }

    int dfs(vector<vector<int>> &grid, int a, int b, int high, int len)
    {
        int area = 0;
        if (grid[a][b] == 1)
        {
            grid[a][b] = 0;
            area++;
        }
        if (a < high - 1 && grid[a + 1][b] == 1)
        {
            area += dfs(grid, a + 1, b, high, len);
        }
        if (a > 0 && grid[a - 1][b] == 1)
        {
            area += dfs(grid, a - 1, b, high, len);
        }
        if (b < len - 1 && grid[a][b + 1] == 1)
        {
            area += dfs(grid, a, b + 1, high, len);
        }
        if (b > 0 && grid[a][b - 1] == 1)
        {
            area += dfs(grid, a, b - 1, high, len);
        }
        return area;
    }
};

int main()
{
}