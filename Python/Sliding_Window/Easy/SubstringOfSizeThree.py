class Solution:
    def countGoodSubstrings(self, s: str) -> int:



# driver program
if __name__ == '__main__':
    # initialize strings
    s1: str = "xyzzaz"
    s2: str = "aababcabc"

    # solution class instance
    Solution = Solution()

    # output
    print(f"The number of good substrings of size three in {s1} is {Solution.countGoodSubstrings(s1)}.")
    print(f"The number of good substrings of size three in {s2} is {Solution.countGoodSubstrings(s2)}.")
