from typing import List


class Solution:
    def minOperations(self, logs: List[str]) -> int:
        stk = []                                             # create empty stack to track folders

        for i in logs:                                       # loop through logs
                if(i == "../" and stk):                      # if we see "../" then pop from the stack to go to parent folder
                    stk.pop()
                elif(i == "./" or (i == "../" and not stk)): # if we see "./" or "../" with an empty stack then do nothing 
                    continue
                else:                                        # otherwise append the folder
                    stk.append(i)
            
        return len(stk)                                      # return the length of the folder
    

# driver program
if __name__ == '__main__':
    # initialize logs
    l1 = ["d1/","d2/","../","d21/","./"]
    l2 = ["d1/","d2/","./","d3/","../","d31/"]
    l3 = ["d1/","../","../","../"]
    l4 = ["./","../","./"]

    # solution class instance
    Solution = Solution()

    # output
    print(f"The minimum number of operations needed to go back to the main folder for {l1} is {Solution.minOperations(l1)}")
    print(f"The minimum number of operations needed to go back to the main folder for {l2} is {Solution.minOperations(l2)}")
    print(f"The minimum number of operations needed to go back to the main folder for {l3} is {Solution.minOperations(l3)}")
    print(f"The minimum number of operations needed to go back to the main folder for {l4} is {Solution.minOperations(l4)}")