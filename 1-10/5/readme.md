## 最长回文子串

[连接](https://leetcode-cn.com/problems/longest-palindromic-substring)

给你一个字符串 s，找到 s 中最长的回文子串。

## eg1

```
输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。
```

## eg2

```
输入：s = "cbbd"
输出："bb"
```

## eg3

```
输入：s = "a"
输出："a"
```

## eg4

```
输入：s = "ac"
输出："a"
```

## dp

如何判断回文？

```
当 s.size>2 时，当前串首尾字符相等，并且串减去首尾字符是一个回文，
当 s.size==1 时即为回文，当 s.size==2 并且两个字符相等时为回文。
当 s.size>2 时，当首尾字符相等，去掉首尾字符后的串如果是回文，即整个就是回文。
```

所以，规划方程为：arr[i][j]=arr[i+1][j-1]
