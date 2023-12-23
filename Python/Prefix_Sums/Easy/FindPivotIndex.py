from typing import List

class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        partial = 0                             # set partial sum to 0
        total = sum(nums)                       # set total to sum of all values in nums array

        for i in range(len(nums)):              # iterate through nums array
            total -= nums[i]                    # subtract the current value from the total
            if(total == partial): return i      # if the total is equal to partial then return the current index
            partial += nums[i]                  # otherwise add the current value to the partial
        return -1                               # if there is no pivot index then return -1
    
if __name__ == '__main__':
    #initialize lists
    n1 = [1,7,3,6,5,6]
    n2 = [1,2,3]
    n3 = [2,1,-1]

    # solution class instance
    Solution = Solution()

    # output
    print(f"The pivot index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right for list one is {Solution.pivotIndex(n1)}")
    print(f"The pivot index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right for list two is {Solution.pivotIndex(n2)}")
    print(f"The pivot index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right for list three is {Solution.pivotIndex(n3)}")
    