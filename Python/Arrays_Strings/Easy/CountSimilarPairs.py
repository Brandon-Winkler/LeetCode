from typing import List


class Solution:
    def similarPairs(self, words: List[str]) -> int:


# driver program
if __name__ == '__main__':
    # initialize string arrays
    w1 = ["aba","aabb","abcd","bac","aabc"]
    w2 = ["aabb","ab","ba"]
    w3 = ["nba","cba","dba"]

    # solution class instance
    Solution = Solution()

    # output
    print(f"The number of pairs of similar strings in {w1} is {Solution.similarPairs(w1)}")
    print(f"The number of pairs of similar strings in {w2} is {Solution.similarPairs(w2)}")
    print(f"The number of pairs of similar strings in {w3} is {Solution.similarPairs(w3)}")