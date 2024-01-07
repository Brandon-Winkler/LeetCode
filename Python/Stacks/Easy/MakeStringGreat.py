class Solution:
    def makeGood(self, s: str) -> str:


# driver program
if __name__ == '__main__':
    # initialize strings
    s1 = "leEeetcode"
    s2 = "abBAcC"
    s3 = "s"

    # solution class instance
    Solution = Solution()

    # output
    print(f"{s1} after making the string great is {Solution.makeGood(s1)}")
    print(f"{s2} after making the string great is {Solution.makeGood(s2)}")
    print(f"{s3} after making the string great is {Solution.makeGood(s3)}")