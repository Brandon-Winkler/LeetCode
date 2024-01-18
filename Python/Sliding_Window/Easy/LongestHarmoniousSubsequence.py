from typing import List

class Solution:
    def findLHS(self, nums: List[int]) -> int:



# driver program
if __name__ == '__main__':
    # initialize arrays
    a1 = [1,3,2,2,5,2,3,7]
    a2 = [1,2,3,4]
    a3 = [1,1,1,1]

    # solution class instance
    Solution = Solution()

    # output
    print(f"The longest harmoneous subsequence for {a1} is of length {Solution.findLHS(a1)}")
    print(f"The longest harmoneous subsequence for {a2} is of length {Solution.findLHS(a2)}")
    print(f"The longest harmoneous subsequence for {a3} is of length {Solution.findLHS(a3)}")