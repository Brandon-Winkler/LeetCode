class Solution:
    def smallestNumber(self, pattern: str) -> str:



# driver program
if __name__ == '__main__':
    # initialize strings
    s1 = "IIIDIDDD"
    s2 = "DDD"
    
    # solution class instance
    Solution = Solution()

    # output
    print(f"The smallest number you can get from {s1} is {Solution.smallestNumber(s1)}")
    print(f"The smallest number you can get from {s2} is {Solution.smallestNumber(s2)}")

