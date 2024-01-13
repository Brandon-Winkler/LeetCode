class Solution:
    def minSwaps(self, s: str) -> int:



# driver program
if __name__ == '__main__':
    # initialize strings
    s1 = "][]["
    s2 = "]]][[["
    s3 = "[]"

    # solution class instance
    Solution = Solution()

    # output
    print(f"The minimum number of swaps to make {s1} balanced is {Solution.minSwaps(s1)}")
    print(f"The minimum number of swaps to make {s2} balanced is {Solution.minSwaps(s2)}")
    print(f"The minimum number of swaps to make {s3} balanced is {Solution.minSwaps(s3)}")