from typing import List

class Solution:
    def minimumCardPickup(self, cards: List[int]) -> int:
        table = {}                          # create hash table to track indices of current values
        mini = hand = len(cards)+1          # set minimum and hand variables to the length of the cards plus one to compare when we return

        for i,n in enumerate(cards):        # loop through the cards
            if(n in table):                 # if the value is in the table
                diff = i-table[n]+1         # calculate the difference between the current index and the index in the table for the current value
                mini = min(mini,diff)       # minimum is minimum between the current minimum and the calculated difference
            table[n] = i                    # update the table at current value to reflect current index

        return mini if hand > mini else -1  # if our hand is greater than the minimum then we have our minimum number of cards if not the we don't have a minimum

# driver program
if __name__ == '__main__':
    # initialze card arrays
    c1 = [3,4,2,3,4,7]
    c2 = [1,0,5,3]

    # solution class instance
    Solution = Solution()

    # output
    print(f"The minimum number of consecutive cards you have to pick up to have a pair of matching cards for {c1} is {Solution.minimumCardPickup(c1)}")
    print(f"The minimum number of consecutive cards you have to pick up to have a pair of matching cards for {c2} is {Solution.minimumCardPickup(c2)}")