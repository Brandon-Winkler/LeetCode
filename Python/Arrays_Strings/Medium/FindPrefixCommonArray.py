from typing import List


class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:


# driver program
if __name__ == '__main__':
    #  initialize array pairs
    a1 = [1,3,2,4]
    b1 = [3,1,2,4]

    a2 = [2,3,1]
    b2 = [3,1,2]

    # solution class instance
    Solution = Solution()

    # output
    print(f"The prefix common array of {a1} and {b1} is {Solution.findThePrefixCommonArray(a1,b1)}")
    print(f"The prefix common array of {a2} and {b2} is {Solution.findThePrefixCommonArray(a2,b2)}")