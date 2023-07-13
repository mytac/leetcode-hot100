class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        n = numRows
        res = []
        res.append([1])
        for i in range(1, n):
            subarr = [0 for j in range(i+1)]
            for j, value in enumerate(subarr):
                if j == 0 or j == i:
                    subarr[j] = 1
                else:
                    subarr[j] = res[i-1][j-1]+res[i-1][j]
            print(subarr)
            res.append(subarr)
        return res


so = Solution()
print(so.generate(4))
