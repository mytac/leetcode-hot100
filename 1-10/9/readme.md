## 17. 电话号码的字母组合

[连接](https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/)

给定一个仅包含数字  2-9  的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
![demo](https://assets.leetcode-cn.com/aliyun-lc-upload/original_images/17_telephone_keypad.png)

### eg1

```
输入：digits = "23"
输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
```

### eg2

```
输入：digits = ""
输出：[]
```

### eg3

```
输入：digits = "2"
输出：["a","b","c"]
```

提示：

```
0 <= digits.length <= 4
digits[i] 是范围 ['2', '9'] 的一个数字。
```

## 解析

排列组合就要想到回溯，之前还想拿 ascii 码套公式输出，发现更复杂了。这道题还是很简单的，主要卡在 c++语法上了。整个问题直接抽象为排列组合题就 ok。

比如对于 ab、cd、ef 这三个集合的排列组合。

```
       ab
      / \
    cd   cd
    /\   /\
  ef ef ef ef
```

思路就是，当某个结果到达出口时，就要回溯到上一个结果，具体的实现为 dfs。
