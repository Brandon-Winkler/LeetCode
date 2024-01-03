from typing import List


class Solution:
    def getAverages(self, nums: List[int], k: int) -> List[int]:
        r = 2*k+1                                   # calculate the radius of the subarrays

        if(r > len(nums)): return [-1]*len(nums)    # if the radius is greater than the length of the array then we don't have enough space to calculate averages so return array of -1
        
        aves = []                                   # allocate space for averages
        total = 0                                   # keep a running sum for each index at middle of radius

        for i in range(r): total+=nums[i]           # calculate the total for the first subarray

        aves.append(total//r)                       # calculate average for first subarray and append it to current averages

        for i in range(len(nums)-r):                # loop through the length of nums minus the radius
            total-=nums[i]                          # calculate next subarray total by subtracting the value at the current index from current total and
            total+=nums[i+r]                        # add the value at the index to the right of current subarray 
            aves.append(total//r)                   # append new total divided by radius

        n = [-1]*k                                  # account for numbers with inefficient radius by appending and prepending arrays of -1
        return n+aves+n
    

# driver program
if __name__ == '__main__':
    # initialize arrays
    a1 = [7,4,3,9,1,8,5,2,6]
    a2 = [100000]
    a3 = [8]

    # solution class instance
    Solution = Solution()

    # output
    print(f"The array of averages for {a1} with a radius of 3 is {Solution.getAverages(a1,3)}")
    print(f"The array of averages for {a1} with a radius of 2 is {Solution.getAverages(a1,2)}")
    print(f"The array of averages for {a2} with a radius of 0 is {Solution.getAverages(a2,0)}")
    print(f"The array of averages for {a3} with a radius of 1000 is {Solution.getAverages(a3,1000)}")