from typing import List

class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        partial = 0
        total = sum(nums)

        for i in range(len(nums)):
            total -= nums[i]
            if(total == partial): return i
            partial += nums[i]
        return -1
    
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
    