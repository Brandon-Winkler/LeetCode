from typing import List
from itertools import accumulate

class Solution:
    def corpFlightBookings(self, bookings: List[List[int]], n: int) -> List[int]:
        totals = [0]*(n+1)                      # initialize totals array with length n plus one

        for l,r,s in bookings:                  # loop through bookings
            totals[l-1] += s                    # add number of seats to the left minus one index
            totals[r] -= s                      # subtract numbers of seats from the right side to track the difference of future prefix sums

        return list(accumulate(totals[:-1]))    # return the prefix sum list from 0 to last index
    
# driver program
if __name__ == '__main__':
    # initialize bookings
    b1 = [[1,2,10],[2,3,20],[2,5,25]]
    b2 = [[1,2,10],[2,2,15]]

    # Solution class instance
    Solution = Solution()

    # output
    print(f"The total number of seats reserved for each flight in the first bookings is {Solution.corpFlightBookings(b1,5)}")
    print(f"The total number of seats reserved for each flight in the second bookings is {Solution.corpFlightBookings(b2,2)}")