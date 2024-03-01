class Solution:
    def countGoodSubstrings(self, s: str) -> int:
        # for every string of length 3 add one if its set length is equal to three
        return sum(1 for c in range(len(s)-3+1) if len(set(s[c:c+3])) == 3)


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
