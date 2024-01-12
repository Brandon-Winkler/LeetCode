class Solution:
    def removeDuplicates(self, s: str, k: int) -> str:



# driver program
if __name__ == '__main__':
    # initialize strings
    s1 = "abcd"
    s2 = "deeedbbcccbdaa"
    s3 = "pbbcggttciiippooaais"

    # solution class instance
    Solution = Solution()

    # output
    print(f"{s1} after removal of 2 adjacent duplicates is {Solution.removeDuplicates(s1,2)}")
    print(f"{s2} after removal of 3 adjacent duplicates is {Solution.removeDuplicates(s2,3)}")
    print(f"{s3} after removal of 2 adjacent duplicates is {Solution.removeDuplicates(s3,2)}")