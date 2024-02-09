from typing import List


class Solution:
    def buildArray(self, target: List[int], n: int) -> List[str]:


# driver program
if __name__ == '__main__':
    # initialize targets
    t1 = [1,3]
    t2 = [1,2,3]
    t3 = [1,2]

    # solution class instance
    Solution = Solution()

    # output
    print(f"The stack operations need to build {t1} are {Solution.buildArray(t1,3)}")
    print(f"The stack operations need to build {t2} are {Solution.buildArray(t2,3)}")
    print(f"The stack operations need to build {t3} are {Solution.buildArray(t3,4)}")