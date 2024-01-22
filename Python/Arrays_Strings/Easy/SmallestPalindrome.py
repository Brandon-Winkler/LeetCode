class Solution:
    def makeSmallestPalindrome(self, s: str) -> str:


# driver program
if __name__ == '__main__':
    #initialize strings
    s1 = "egcfe"
    s2 = "abcd"
    s3 = "seven"

    # solution class instance
    Solution = Solution()

    #output
    print(f"The minimum number of operations to make {s1} a palindrome is {Solution.makeSmallestPalindrome(s1)}")
    print(f"The minimum number of operations to make {s2} a palindrome is {Solution.makeSmallestPalindrome(s2)}")
    print(f"The minimum number of operations to make {s3} a palindrome is {Solution.makeSmallestPalindrome(s3)}")