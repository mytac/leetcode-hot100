class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        if (n <= 2):
            return n
        arr = [0 for j in range(n)]
        arr[0] = 1
        arr[1] = 2
        if (n < 3):
            return arr[n-1]
        for i in range(2, n):
            print(i)
            arr[i] = arr[i-1]+arr[i-2]
        return arr[n-1]


so = Solution()
print(so.climbStairs(2))
