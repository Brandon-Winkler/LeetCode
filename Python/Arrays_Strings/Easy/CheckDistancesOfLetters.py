from typing import List

class Solution:
    def checkDistances(self, s: str, distance: List[int]) -> bool:
        


# driver program
if __name__ == '__main__':
    # initiialize strings and distances
    s1 = "abaccb"
    d1 = [1,3,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]

    s2 = "aa"
    d2 = [1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]

    # solution class instance
    Solution = Solution()

    # output
    if(Solution.checkDistances(s1,d1)): print(f"{s1} is a well spaced string")
    else: print(f"{s1} is not a well spaced string")

    if(Solution.checkDistances(s2,d2)): print(f"{s2} is a well spaced string")
    else: print(f"{s2} is not a well spaced string")