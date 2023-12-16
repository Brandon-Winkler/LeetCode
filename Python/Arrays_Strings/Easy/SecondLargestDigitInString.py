class Solution:
    def secondHighest(self, s: str) -> int:
        digits = []                                 # create digits list to add nums to
        for i in s:                                 # loop through string
            if(i.isdigit() and i not in digits):    # if char is a digit and char isn't in digits list
                digits.append(i)                    # append char digit to list
        if(len(digits) < 2): return -1              # since we prevented duplicates from being in the list if the list has only one value in it then there is not second highest so return -1
        return int(sorted(digits)[-2])              # otherwise sort the list and return the value just befroe the end
    

# driver program
if __name__ == '__main__':
    #initialize strings
    s1 = "dfa12321afd"
    s2 = "abc1111"

    # solution class instance
    Solution = Solution()

    # output
    print(Solution.secondHighest(s1))
    print(Solution.secondHighest(s2))