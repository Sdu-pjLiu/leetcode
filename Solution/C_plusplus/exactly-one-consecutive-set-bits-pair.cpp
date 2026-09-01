#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool consecutiveSetBits(int n)
    {
        int sum = 0;
        while (n > 0)
        {
            int right = n % 2;
            int left = (n / 2) % 2;
            if (left & right == 1)
            {
                sum++;
            }
            n = n / 2;
        }
        if (sum == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Solution sol;
    int n = 5;
    cout << sol.consecutiveSetBits(5) << endl;
}