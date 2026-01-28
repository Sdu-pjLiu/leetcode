# [2183. 统计可以被 K 整除的下标对数目](https://leetcode.cn/problems/count-array-pairs-divisible-by-k/description/)

给你一个下标从 **0**  开始、长度为 <code>n</code> 的整数数组 <code>nums</code> 和一个整数 <code>k</code> ，返回满足下述条件的下标对 <code>(i, j)</code> 的数目：

- <code>0 <= i < j <= n - 1</code> 且
- <code>nums[i] * nums[j]</code> 能被 <code>k</code> 整除。

**示例 1：**

```
**输入：** nums = [1,2,3,4,5], k = 2
**输出：** 7
**解释：** 
共有 7 对下标的对应积可以被 2 整除：
(0, 1)、(0, 3)、(1, 2)、(1, 3)、(1, 4)、(2, 3) 和 (3, 4)
它们的积分别是 2、4、6、8、10、12 和 20 。
其他下标对，例如 (0, 2) 和 (2, 4) 的乘积分别是 3 和 15 ，都无法被 2 整除。    
```

**示例 2：**

```
**输入：** nums = [1,2,3,4], k = 5
**输出：** 0
**解释：** 不存在对应积可以被 5 整除的下标对。
```

**提示：**

- <code>1 <= nums.length <= 10^5</code>
- <code>1 <= nums[i], k <= 10^5</code>

## Solution
[solution](../../test/count-array-pairs-divisible-by-k.cpp)