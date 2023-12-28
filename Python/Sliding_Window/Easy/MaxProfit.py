from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if(len(prices) == 1 or not prices): return 0        # if we only have one price or no prices then we cannot make a profit

        maxProf = 0                                         # initialize max profit to zero to compare to current profits
        minBuy = prices[0]                                  # initialize min buy to compare to other minimums in profits 

        for price in prices:                                # loop through prices to compare minimums and current profits
            if(price < minBuy): minBuy = price              # if current price is less than the min buy then make the min buy equal to current price
            else:                                           
                curProf = price - minBuy                    # otherwise subtract current price from the minimum buy to get current profit
                if(curProf > maxProf): maxProf = curProf    # if current profit is greater than the max profit then set the max to the current profit

        return maxProf


# driver program
if __name__ == '__main__':
    # initialize stocks
    s1 = [7,1,5,3,6,4]
    s2 = [7,6,4,3,1]
    s3 = [2,4,1]

    # solution class instance
    Solution = Solution()

    # output
    print(f"The maximum profit you can obtain from {s1} is {Solution.maxProfit(s1)}")
    print(f"The maximum profit you can obtain from {s2} is {Solution.maxProfit(s2)}")
    print(f"The maximum profit you can obtain from {s3} is {Solution.maxProfit(s3)}")


'''
WHAT DOESN'T WORK:
The reason why finding the difference between the two pointers doesn't work here is because it requires us to find every combination of 
differences between every number which is not only inefficient but the conditions for moving the pointers are too complicated and possibly 
don't exist for certain test cases. The reason why simply starting at the minimum and finding the max after that doesn't work is because 
the max profit might exist before the minimum. 

WHAT DOES WORK:
The best solution is to find the max profit by starting the minimum at the beginning value and updating it once we find a value that is less 
than it. Then if we find a value that is greater than the minimum we get the difference between the current value and the current minimum and 
use that as our max profit. 

WHY IT WORKS:
This avoids having to find the difference between every combination of numbers by holding a variable reserved for the minimum. This also avoids 
the max profit being before the minimum problem because the current minimum changes as you traverse the array.
'''