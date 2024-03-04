from typing import List


class Solution:
    def buildArray(self, target: List[int], n: int) -> List[str]:
        stk = []                        # initialize stk to compare to target
        ans = []                        # initialize answer output

        for i in range(1,n+1):          # loop through n
            if(stk == target): break    # if the stack matches the target then break to return the output
            stk.append(i)               # append number to stack
            ans.append("Push")          # append corresponding push string to answer output
            if(i not in target):        # if the number is not in the target then
                stk.pop()               # pop from the stack
                ans.append("Pop")       # append corresponding pop string to output

        return ans

# driver program
if __name__ == '__main__':
    # initialize targets
    t1 = [1,3]
    t2 = [1,2,3]
    t3 = [1,2]

    # solution class instance
    Solution = Solution()

    # output
    print(f"The stack operations needed to build {t1} are {Solution.buildArray(t1,3)}")
    print(f"The stack operations needed to build {t2} are {Solution.buildArray(t2,3)}")
    print(f"The stack operations needed to build {t3} are {Solution.buildArray(t3,4)}")