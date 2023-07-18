class Solution(object):
    def countBits(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        arr = [0]
        if n >= 1:
            arr.append(1)  # 1 - 1
        if n >= 2:
            arr.append(1)  # 2 - 1
        for i in range(3, n+1):
            if i % 2 != 0:  # 如果为奇数，就是前一位数+1
                arr.append(int(arr[i-1])+1)
            else:
                j = int(i/2)
                arr.append(arr[j])
        return arr


so = Solution()
print(so.countBits(5))
