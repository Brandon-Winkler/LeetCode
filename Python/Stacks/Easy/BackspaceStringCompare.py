class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        stk1 = []                       # initialize stacks to keep track of previous chars
        stk2 = []

        for i in s:                     # loop through first string to look for # signs
            if(i == '#'):               # if we see a pound sign and the stack isn't empty pop the last character
                if(stk1):
                    stk1.pop()
            else:                       # otherwise append to first stack
                stk1.append(i)

        for j in t:                     # loop through second string and do the same for the second stack
            if(j == '#'):
                if(stk2):
                    stk2.pop()
            else:
                stk2.append(j)

        return str(stk1) == str(stk2)  # compare the two modified strings and return the result


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