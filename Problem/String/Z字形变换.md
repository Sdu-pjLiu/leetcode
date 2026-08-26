# [6. Z 字形变换](https://leetcode.cn/problems/zigzag-conversion/description/)

将一个给定字符串 <code>s</code> 根据给定的行数 <code>numRows</code> ，以从上往下、从左到右进行Z 字形排列。

比如输入字符串为 <code>"PAYPALISHIRING"</code>行数为 <code>3</code> 时，排列如下：

```
P   A   H   N
A P L S I I G
Y   I   R```

之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如：<code>"PAHNAPLSIIGYIR"</code>。

请你实现这个将字符串进行指定行数变换的函数：

```
string convert(string s, int numRows);```

**示例 1：**

```
**输入：** s = "PAYPALISHIRING", numRows = 3
**输出：** "PAHNAPLSIIGYIR"
```

**示例 2：**

```
**输入：** s = "PAYPALISHIRING", numRows = 4
**输出：** "PINALSIGYAHRPI"
**解释：** 
P     I    N
A   L S  I G
Y A   H R
P     I
```

**示例 3：**

```
**输入：** s = "A", numRows = 1
**输出：** "A"
```

**提示：**

- <code>1 <= s.length <= 1000</code>
- <code>s</code> 由英文字母（小写和大写）、<code>','</code> 和 <code>'.'</code> 组成
- <code>1 <= numRows <= 1000</code>

## Solution
[Solution](../../test/zigzag-conversion.cpp)