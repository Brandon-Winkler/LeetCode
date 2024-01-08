class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:



# driver program
if __name__ == '__main__':
    # initialize strings
    s1 = "ab#c"
    t1 = "ad#c"
    s2 = "ab##"
    t2 = "c#d#"
    s3 = "a#c"
    t3 = "b"

    # solution class instance
    Solution = Solution()

    # output
    if(Solution.backspaceCompare(s1,t1)): print(f"{s1} and {t1} are equal when typed")
    else: print(f"{s1} and {t1} are not equal when typed")

    if(Solution.backspaceCompare(s2,t2)): print(f"{s2} and {t2} are equal when typed")
    else: print(f"{s2} and {t2} are not equal when typed")

    if(Solution.backspaceCompare(s3,t3)): print(f"{s3} and {t3} are equal when typed")
    else: print(f"{s3} and {t3} are not equal when typed")