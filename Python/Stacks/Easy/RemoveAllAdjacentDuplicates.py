class Solution:
    def removeDuplicates(self, s: str) -> str:



# driver program
if __name__ == '__main__':
    # initialize strings
    s1 = "abbaca"
    s2 = "azxxzy"

    # solution class instance
    Solution = Solution()

    # output
    print(f"String {s1} after duplicate removal is {Solution.removeDuplicates(s1)}")
    print(f"String {s2} after duplicate removal is {Solution.removeDuplicates(s2)}")