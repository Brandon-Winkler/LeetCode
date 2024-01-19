class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        if(len(s) == 1 or len(s) == 0): return len(s)           # if the string is empty or the length is zero return the length of string

        parens = "()"                                           # create parentheses variable to compare chars
        stk = []                                                # create stack variable to track last seen char
        stk.append(s[0])                                        # append the first char

        for i in range(1,len(s)):                               # loop through the string beginning at the second char until the end
            if(                                                 # if the stack isn't empty and the current parentheses matches opposite of the last seen one then pop from the stack
                stk and 
                (stk[-1] == parens[0] and s[i] == parens[1])
            ):
                stk.pop()
            else:                                               # otherwise append the current parentheses
                stk.append(s[i])
        
        return len(stk)                                         # return the length of the stack



# driver program
if __name__ == '__main__':
    # initialize strings
    s1 = "())"
    s2 = "((("
    s3 = "()"
    s4 = "()))(("

    # solution class instance
    Solution = Solution()

    # output
    print(f"The minimum number of moves to make {s1} valid is {Solution.minAddToMakeValid(s1)}")
    print(f"The minimum number of moves to make {s2} valid is {Solution.minAddToMakeValid(s2)}")
    print(f"The minimum number of moves to make {s3} valid is {Solution.minAddToMakeValid(s3)}")
    print(f"The minimum number of moves to make {s4} valid is {Solution.minAddToMakeValid(s4)}")