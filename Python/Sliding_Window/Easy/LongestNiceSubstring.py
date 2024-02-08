class Solution:
    def longestNiceSubstring(self, s: str) -> str:


# driver program
if __name__ == '__main__':
    # initialize strings
    s1 = "YazaAay"
    s2 = "Bb"
    s3 = "c"

    # solution class instance
    Solution = Solution()

    # output
    print(f"{Solution.longestNiceSubstring(s1)} is the longest nice substring from {s1}")
    print(f"{Solution.longestNiceSubstring(s2)} is the longest nice substring from {s2}")
    print(f"{Solution.longestNiceSubstring(s3)} is the longest nice substring from {s3}")