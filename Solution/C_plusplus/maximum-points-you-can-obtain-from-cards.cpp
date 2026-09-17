# include<bits/stdc++.h>
using namespace std;
#define INT_MAX __INT_MAX__


// 该方法会超时，通过测试用例 39/41
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int min_res = INT_MAX; 
        int len = cardPoints.size();
        int rest_len = len - k; // 剩余长度
        int sum_card = sumScore(cardPoints,0,len); // cardPoints的值总和

        for(int i = 0;i <= k; i++){
            min_res = min(min_res,sumScore(cardPoints,i,rest_len));
        }
        int res = sum_card - min_res;
        return res;
    }
    int sumScore(vector<int>& cardPoints, int start_index, int k){
        int sum = 0;
        for(int i = start_index; i< start_index + k;i++){
            sum += cardPoints[i];
        }
        return sum;
    }
};


// chatgpt优化后的逻辑
class Solution_2 {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        // cardPoints 中一共有多少张牌
        int n = cardPoints.size();

        /*
         * 一共 n 张牌，需要拿走 k 张牌，
         * 那么最后一定会剩下 n-k 张牌。
         *
         * 因为每次只能从数组最左边或者最右边拿，
         * 所以最后剩下的 n-k 张牌一定是连续的。
         */
        int rest_len = n - k;

        /*
         * 特殊情况：
         * 如果 rest_len == 0，
         * 说明 k == n，也就是所有牌都需要拿走。
         *
         * 那么答案就是所有牌的总和。
         */
        if (rest_len == 0) {
            int sum = 0;

            /*
             * 范围 for 循环：
             * 依次取出 cardPoints 中的每一个元素。
             *
             * 例如：
             * cardPoints = {1, 2, 3}
             *
             * 第一次 x = 1
             * 第二次 x = 2
             * 第三次 x = 3
             */
            for (int x : cardPoints) {
                sum += x;
            }

            return sum;
        }


        /*
         * 计算所有牌的总分。
         *
         * 例如：
         * cardPoints = {1, 2, 3, 4}
         *
         * total = 1 + 2 + 3 + 4 = 10
         */
        int total = 0;

        for (int x : cardPoints) {
            total += x;
        }


        /*
         * ---------------------------
         * 开始使用滑动窗口
         * ---------------------------
         *
         * 我们需要找到：
         *
         * 长度为 rest_len 的连续子数组中，
         * 元素和最小的那个。
         *
         * 因为：
         *
         * 最大拿牌得分
         * = 所有牌总分 - 剩下牌的最小总分
         */


        /*
         * window：
         * 当前窗口中所有元素的总和。
         *
         * 先计算第一个窗口。
         *
         * 例如：
         *
         * cardPoints = {1,2,3,4,5,6,1}
         * k = 3
         *
         * n = 7
         * rest_len = 7 - 3 = 4
         *
         * 第一个窗口就是：
         *
         * [1,2,3,4]
         *
         * window = 1+2+3+4 = 10
         */
        int window = 0;

        for (int i = 0; i < rest_len; i++) {
            window += cardPoints[i];
        }


        /*
         * min_sum：
         * 记录目前找到的最小窗口和。
         *
         * 一开始只有第一个窗口，
         * 所以先让 min_sum = window。
         */
        int min_sum = window;


        /*
         * 开始向右移动窗口。
         *
         * 假设：
         *
         * cardPoints = {1,2,3,4,5,6,1}
         * rest_len = 4
         *
         * 第一个窗口：
         *
         * [1,2,3,4] 5 6 1
         *
         * 然后向右移动一格：
         *
         * 1 [2,3,4,5] 6 1
         *
         * 不需要重新计算 2+3+4+5。
         *
         * 只需要：
         *
         * 原来的 window
         * - 离开窗口的 1
         * + 新进入窗口的 5
         *
         * 即：
         *
         * 新window = 旧window - 1 + 5
         *
         * 这就是“滑动窗口”的核心。
         */
        for (int i = rest_len; i < n; i++) {

            /*
             * cardPoints[i]
             * 是新进入窗口的元素。
             *
             * 所以把它加到 window 中。
             */
            window += cardPoints[i];


            /*
             * cardPoints[i - rest_len]
             * 是刚刚离开窗口的元素。
             *
             * 所以把它从 window 中减掉。
             *
             * 例如：
             *
             * rest_len = 4
             * i = 4
             *
             * i - rest_len
             * = 4 - 4
             * = 0
             *
             * cardPoints[0] 就是第一个离开窗口的元素。
             */
            window -= cardPoints[i - rest_len];


            /*
             * 比较当前窗口和与之前的最小窗口和，
             * 保存更小的那个。
             */
            min_sum = min(min_sum, window);
        }


        /*
         * 最终：
         *
         * 拿走的牌的总分
         * =
         * 所有牌的总分
         * -
         * 留下来的牌的最小总分
         */
        return total - min_sum;
    }
};


// 官方C++解法
class Solution_official {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        // cardPoints 中牌的总数量
        int n = cardPoints.size();

        /*
         * 每次只能从数组的最左边或者最右边拿一张牌。
         *
         * 一共拿走 k 张牌后，会剩下 n-k 张牌。
         *
         * 由于只能从两端拿，所以最后剩下来的 n-k 张牌
         * 一定是原数组中的一个连续区间。
         *
         * 因此问题可以转换成：
         *
         *   最大拿牌得分
         * = 所有牌的总分
         * - 长度为 n-k 的连续子数组的最小和
         *
         * 所以滑动窗口的长度就是 n-k。
         */
        int windowSize = n - k;


        /*
         * 计算第一个滑动窗口的元素总和。
         *
         * accumulate(first, last, init)
         * 用来计算 [first, last) 区间内所有元素的累加结果。
         *
         * 注意：[first, last) 是左闭右开区间，
         * first 指向的元素参与计算，
         * last 指向的元素不参与计算。
         *
         * 这里计算：
         *
         * cardPoints[0]
         * + cardPoints[1]
         * + ...
         * + cardPoints[windowSize - 1]
         *
         * 最后的 0 是累加的初始值。
         */
        int sum = accumulate(
            cardPoints.begin(),
            cardPoints.begin() + windowSize,
            0
        );

        // 当前找到的最小窗口和。
        // 一开始只有第一个窗口，所以直接将 sum 作为初始值。
        int minSum = sum;


        /*
         * 从第二个窗口开始，不断向右移动滑动窗口。
         *
         * i 表示当前新进入窗口的元素下标。
         *
         * 假设：
         *
         * cardPoints = [1, 2, 3, 4, 5, 6, 1]
         * windowSize = 4
         *
         * 第一个窗口：
         *
         * [1, 2, 3, 4] 5 6 1
         *
         * 当 i = 4 时，窗口向右移动：
         *
         * 1 [2, 3, 4, 5] 6 1
         *
         * 其中：
         * cardPoints[4] = 5        新进入窗口
         * cardPoints[0] = 1        离开窗口
         *
         * 因此不需要重新计算 2+3+4+5，
         * 只需要：
         *
         * 新窗口和 = 旧窗口和 + 新元素 - 离开的元素
         */
        for (int i = windowSize; i < n; ++i) {

            /*
             * cardPoints[i]
             *     当前从右边新进入窗口的元素。
             *
             * cardPoints[i - windowSize]
             *     当前从左边离开窗口的元素。
             *
             * 所以：
             *
             * 新窗口和
             * = 旧窗口和
             * + 新进入元素
             * - 离开元素
             */
            sum += cardPoints[i] - cardPoints[i - windowSize];

            // 保存所有长度为 windowSize 的窗口中的最小和
            minSum = min(minSum, sum);
        }


        /*
         * accumulate(begin, end, 0)
         * 计算整个 cardPoints 数组的元素总和。
         *
         * 最终：
         *
         * 最大拿牌得分
         * = 所有牌的总分 - 剩余连续区间的最小总分
         */
        return accumulate(
            cardPoints.begin(),
            cardPoints.end(),
            0
        ) - minSum;
    }
};