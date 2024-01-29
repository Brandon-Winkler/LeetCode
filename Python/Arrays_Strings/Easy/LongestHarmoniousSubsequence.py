from typing import List
from collections import defaultdict

class Solution:
    def findLHS(self, nums: List[int]) -> int:
        table = defaultdict(int)                    # create default dict for frequency table
        ans = 0                                     # initialize output variable

        for i in nums: table[i] += 1                # create frequency table

        for key in table.keys():                    # loop through table keys
            if(                                     # if the current key has a greater key of plus one in the table then it is a minimum
                key+1 in table and 
                table[key]+table[key+1] > ans       # and if the current key and its next greater key's frequency is greater then the current frequency
            ):
                ans = table[key]+table[key+1]       # update the output to be the frequency of the current key plus the frequency of the next greater key

        return ans


# driver program
if __name__ == '__main__':
    # initialize arrays
    a1 = [1,3,2,2,5,2,3,7]
    a2 = [1,2,3,4]
    a3 = [1,1,1,1]
    a4 = [1,3,5,7,9,11,13,15,17]
    a5 = [-3,-1,-1,-1,-3,-2]
    a6 = [1,2,2,3,4,5,1,1,1,1]

    # solution class instance
    Solution = Solution()

    # output
    print(f"The longest harmoneous subsequence for {a1} is of length {Solution.findLHS(a1)}")
    print(f"The longest harmoneous subsequence for {a2} is of length {Solution.findLHS(a2)}")
    print(f"The longest harmoneous subsequence for {a3} is of length {Solution.findLHS(a3)}")
    print(f"The longest harmoneous subsequence for {a4} is of length {Solution.findLHS(a4)}")
    print(f"The longest harmoneous subsequence for {a5} is of length {Solution.findLHS(a5)}")
    print(f"The longest harmoneous subsequence for {a6} is of length {Solution.findLHS(a6)}")


    """
    WHAT DOESN'T WORK:
    Using max and min variables and updating them as you loop through the array and then finding all the max's
    and min's in the array to build the sequence doesn't work. The reason is because this approach doesn't account
    for the possiblity of there being two pairs who's difference is 1. It also doesn't work when you include negative
    numbers because it will update the max and min even if there is a longer subsequence possible

    WHAT DOES WORK:
    Using a hash table to make a frequency table for each value in the array. The reason this works is because
    we only need to check the keys of the table to find out if the current key plus 1 exists. If it does then
    we have found a possible minimum and we can add the frequencies of the current key and the plus 1 key.
    Then we can check is the new possible frequency is greater than the current one. The longest subsequence
    will always be obtained because we always have a possible minimum and maximum and if we don't then the
    answer will be 0. 
    """