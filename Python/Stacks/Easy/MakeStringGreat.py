class Solution:
    def makeGood(self, s: str) -> str:
        if(len(s) == 1 or len(s) == 0): return s                            # if the string is empty or just one character then return the string

        stk = []                                                            # create a stack to check last character seen
        stk.append(s[0])                                                    # put first character into stack to check at beginning of traversal

        for i in range(1,len(s)):                                           # loop through string beginning a 1st index
            if(                                                             # if the stack isn't empty and there is a lower case version on either side of the character then pop the last character on the stack
                stk and 
                (s[i] == stk[-1].upper() and s[i].lower() == stk[-1] or 
                s[i].upper() == stk[-1] and s[i] == stk[-1].lower())
            ):
                stk.pop()
            else: stk.append(s[i])                                         # otherwise append the current character onto the stack
        
        return "".join(stk)


# driver program
if __name__ == '__main__':
    # initialize strings
    s1 = "leEeetcode"
    s2 = "abBAcC"
    s3 = "s"
    s4 = "Pp"
    s5 = "kkdsFuqUfSDKK"

    # solution class instance
    Solution = Solution()

    # output
    print(f"{s1} after making the string great is {Solution.makeGood(s1)}")
    print(f"{s2} after making the string great is {Solution.makeGood(s2)}")
    print(f"{s3} after making the string great is {Solution.makeGood(s3)}")
    print(f"{s4} after making the string great is {Solution.makeGood(s4)}")
    print(f"{s5} after making the string great is {Solution.makeGood(s5)}")