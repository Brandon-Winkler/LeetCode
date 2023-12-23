from typing import List

class Solution:
    def partitionDisjoint(self, nums: List[int]) -> int:
        l_max = r_max = nums[0]             # set left and right max's to initial value of nums
        partition = 0                       # set partition to zero
        for i in range(1,len(nums)):        # loop through nums beginning at index one since we have our max's set to initial
            r_max = max(nums[i], r_max)     # set the right max to be the max between the current value and the right max
            if(nums[i] < l_max):            # if the current value is less than the left max then we still have a greater left maximum
                l_max = r_max               # set left max to the right max
                partition = i               # and set the partition to be the current index
        return partition+1                  # return the partition plus one to account for zero based indexing
    
#driver program
if __name__ == '__main__':
    # initialize number arrays
    n1 = [5,0,3,8,6]
    n2 = [1,1,1,0,6,12]
    n3 = [90,47,69,10,43,92,31,73,61,97]

    # solution class instance
    Solution = Solution()

    # output
    print(f"The length of the left subarray after partitioning so that all values are less than the right subarray for {n1} is {Solution.partitionDisjoint(n1)}")
    print(f"The length of the left subarray after partitioning so that all values are less than the right subarray for {n2} is {Solution.partitionDisjoint(n2)}")
    print(f"The length of the left subarray after partitioning so that all values are less than the right subarray for {n3} is {Solution.partitionDisjoint(n3)}")