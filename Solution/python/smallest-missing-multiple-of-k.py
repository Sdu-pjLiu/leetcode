from typing import List
from itertools import count
## 循环查询，求出最小倍数

class Solution:
    def missingMultiple(self, nums: List[int], k: int) -> int:
        a:int = 1
        is_t:bool = True
        while(is_t):
            is_t = False
            for i in range(len(nums)):
                if(nums[i] == a*k):
                    a += 1
                    is_t = True
        return a*k


class Solution2:
    def missingMultiple(self, nums: List[int], k: int) -> int:
        # 将 nums 转换成集合，方便快速判断某个数字是否存在，查询为O(1)
        nums_set = set(nums)

        # count(1) 会从 1 开始不断生成整数：
        # 1, 2, 3, 4, 5, ...
        for i in count(1):

            # 计算 k 的第 i 个正整数倍：
            # i = 1 → k
            # i = 2 → 2k
            # i = 3 → 3k
            # ...
            if i * k not in nums_set:

                # 如果这个倍数不在 nums 中，
                # 那么它就是最小的缺失正整数倍数
                return i * k

num:List[int] = [8,2,3,4,6]
k:int = 2
print(Solution().missingMultiple(num,k))