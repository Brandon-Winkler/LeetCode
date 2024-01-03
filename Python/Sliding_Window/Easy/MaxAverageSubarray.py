from typing import List


class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        cur = res = sum(nums[0:k])      # initialize the current and result variables to the sum of the initial subarray of length k

        for i in range(len(nums) - k):  # loop through the length of the array minus k to cut time complexity
            cur += nums[i+k] - nums[i]  # calculate the other subarrays by adding the numbers ahead of the initial subarray and discard values behind initial subarray by subtracting the values at the current index 
            res = max(cur, res)         # update result to max between the current value and the result

        return float(res)/k             # return the max divided by k
    

# driver program
if __name__ == '__main__':
    # initialize arrays
    a1 = [1,12,-5,-6,50,3]
    a2 = [5]
    a3 = [-1]

    # solution class instance
    Solution = Solution()

    # output
    print(f"The maximum average of a subarray whose length is 4 in {a1} is {Solution.findMaxAverage(a1,4)}")
    print(f"The maximum average of a subarray whose length is 1 in {a2} is {Solution.findMaxAverage(a2,1)}")
    print(f"The maximum average of a subarray whose length is 1 in {a3} is {Solution.findMaxAverage(a3,1)}")



'''
WHAT DOESN'T WORK:
Using left and right pointers to create a windwow of length k and creating a subarray from the window, finding that
windows average and the max average of each window. This will not work in test cases where the arrays are very large
because it requires us to find every single average of every single subarray of length k.

WHAT DOES WORK:
Set a current and result variable to the sum of the initial subarray of length k. Loop through the array lengh minus k. 
Add to the current variable the value at ith plus kth index minus the value at the current index. Update the result to
be the max between the result and the current variable.

WHY IT WORKS:
This avoids creating a subarray every time we need to find an average and cuts the time complexity by only traversing up
to the length of the array minus k. Then we calculate each subarray by adding the value at the ith plus kth index and
subtracting the value at the current index. Whatever our max is at the end we return the max divided by k. 
'''