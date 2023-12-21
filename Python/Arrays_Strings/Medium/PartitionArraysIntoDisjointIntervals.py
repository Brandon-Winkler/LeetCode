from typing import List

class Solution:
    def partitionDisjoint(self, nums: List[int]) -> int:
        l_max = r_max = nums[0]
        partition = 0
        for i in range(1,len(nums)):
            r_max = max(nums[i], r_max)
            if(nums[i] < l_max):
                l_max = r_max
                partition = i
        return partition+1
    
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