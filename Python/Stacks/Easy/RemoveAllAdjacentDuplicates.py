class Solution:
    def removeDuplicates(self, s: str) -> str:
        if(len(s) == 1 or len(s) == 0): return s        # if we only have one character or no characters return the string

        stk = []                                        # initialize the stack to track duplicates
        stk.append(s[0])                                # push the first letter of the string to make sure stack isn't empty

        for i in range(1,len(s)):                       # loop through string to look for duplicates
            if(stk and s[i] == stk[-1]): stk.pop()      # if the current character is equal to the top of the stack then remove the top
            else: stk.append(s[i])                      # otherwise append the current character

        return "".join(stk)                             # return the modifed string


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