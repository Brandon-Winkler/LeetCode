from typing import List


class Solution:
    def isPrefixString(self, s: str, words: List[str]) -> bool:


# driver program
if __name__ == '__main__':
    # initialize string array pairs
    s1 = "iloveleetcode"
    a1 = ["i","love","leetcode","apples"]
    s2 = "iloveleetcode"
    a2 = ["apples","i","love","leetcode"]

    # solution class instance
    Solution = Solution()

    # output
    if(Solution.isPrefixString(s1,a1)): print(f"{s1} is a prefix of {a1}")
    else: print(f"{s1} is not a prefix of {a1}")

    if(Solution.isPrefixString(s2,a2)): print(f"{s2} is a prefix of {a2}")
    else: print(f"{s2} is not a prefix of {a2}")