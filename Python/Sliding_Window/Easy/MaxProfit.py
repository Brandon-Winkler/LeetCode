from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:

# driver program
if __name__ == '__main__':
    # initialize stocks
    s1 = [7,1,5,3,6,4]
    s2 = [7,6,4,3,1]

    # solution class instance
    Solution = Solution()

    # output
    print(f"The maximum profit you can obtain from {s1} is {Solution.maxProfit(s1)}")
    print(f"The maximum profit you can obtain from {s2} is {Solution.maxProfit(s2)}")