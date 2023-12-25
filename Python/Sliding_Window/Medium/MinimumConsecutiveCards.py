from typing import List

class Solution:
    def minimumCardPickup(self, cards: List[int]) -> int:

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