## 19. 删除链表的倒数第 N 个结点

给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

进阶：你能尝试使用一趟扫描实现吗？

### eg

```
输入：head = [1,2,3,4,5], n = 2
输出：[1,2,3,5]
```

### 思路

要求一趟扫描，这里考虑是用两个指针，i,j，j 为 i+n 的位置，当 j 扫描到头了，i 所指的位置就是倒数第 n 个节点的位置，之后删除即可！！

p.s 上述不严谨，一开始就要取 n+1，因为只要删除节点的前驱。这里有个特殊情况是，j 指到链表结尾了，但 i 所在位置不存在，即头节点的前驱是不存在的，此时就是要删除头节点。