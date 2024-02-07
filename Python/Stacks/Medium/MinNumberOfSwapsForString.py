class Solution:
    def minSwaps(self, s: str) -> int:
        count = 0                           # create count for output
        stk = []                            # create stack to track what brackets came before

        for i in s:                         # loop through string
            if(i == "["): stk.append("[")   # if we see an open bracket append it to the stack
            else:                           # otherwise...
                if(not stk):                # if stack is empty then...
                    stk.append("]")         # append closed bracket
                    count += 1              # increment count
                else:                       # otherwise...
                    stk.pop()               # pop from stack

        return count


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