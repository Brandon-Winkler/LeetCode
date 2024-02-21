from typing import List


class Solution:
    def countPairs(self, nums: List[int], target: int) -> int:



# driver program
if __name__ == '__main__':
    # initialize arrays
    n1 = [-1,1,2,3,1]
    n2 = [-6,2,5,-2,-7,-1,3]
    
    # solution class instance
    Solution = Solution()

    # output
    print(f"The number of pairs whose sum is less than 2 in {n1} is {Solution.countPairs(n1,2)}.")
    print(f"The number of pairs whose sum is less than -2 in {n2} is {Solution.countPairs(n2,-2)}.")