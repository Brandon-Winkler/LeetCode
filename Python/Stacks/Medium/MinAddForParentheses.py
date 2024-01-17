class Solution:
    def minAddToMakeValid(self, s: str) -> int:



# driver program
if __name__ == '__main__':
    # initialize strings
    s1 = "())"
    s2 = "((("
    s3 = "()"

    # solution class instance
    Solution = Solution()

    # output
    print(f"The minimum number of moves to make {s1} valid is {Solution.minAddToMakeValid(s1)}")
    print(f"The minimum number of moves to make {s2} valid is {Solution.minAddToMakeValid(s2)}")
    print(f"The minimum number of moves to make {s3} valid is {Solution.minAddToMakeValid(s3)}")