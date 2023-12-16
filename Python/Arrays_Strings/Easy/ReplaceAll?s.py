class Solution:
    def modifyString(self, s: str) -> str:
        s = list(s)                                     # convert string to list to make it iterable
        for c in range(len(s)):                         # loop through string list and check if character is ?
            if(s[c] == '?'):
                for i in "xyz":                         # if character is ? then loop through three other characters to replace ?
                    if(
                        (c == 0 or s[c-1] != i) and     # if we are at index 0 or if previous value is not equal to the char we are on out of the three
                        (c+1 == len(s) or s[c+1] != i)  # if we are at last index or the value at next index is not equal to the char we are on out of the three 
                    ):
                        s[c] = i                        # set the ? to the char we are on out of the three
                        break
        return "".join(s)

# driver program
if __name__ == '__main__':
    # initialize strings
    s1 = "a?b?c"
    s2 = "?????????????"
    s3 = "dkiend"

    # solution class instance
    Solution = Solution()

    #output
    print(Solution.modifyString(s1))
    print(Solution.modifyString(s2))
    print(Solution.modifyString(s3))