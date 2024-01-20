from typing import List


class Solution:
    def garbageCollection(self, garbage: List[str], travel: List[int]) -> int:



# driver program
if __name__ == '__main__':
    # initialize garbage and time
    g1 = ["G","P","GP","GG"]
    t1 = [2,4,3]

    g2 = ["MMM","PGM","GP"]
    t2 = [3,10]

    # solution class instance
    Solution = Solution()

    # output
    print(f"The minimum amount of time to collect all garbage from {g1} with a travel time of {t1} is {Solution.garbageCollection(g1,t1)}")
    print(f"The minimum amount of time to collect all garbage from {g2} with a travel time of {t2} is {Solution.garbageCollection(g2,t2)}")