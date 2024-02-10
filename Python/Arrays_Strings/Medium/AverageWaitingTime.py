from typing import List


class Solution:
    def averageWaitingTime(self, customers: List[List[int]]) -> float:



# driver program
if __name__ == '__main__':
    # initialize customers times
    c1 = [[1,2],[2,5],[4,3]]
    c2 = [[5,2],[5,4],[10,3],[20,1]]

    # solution class instance
    Solution = Solution()

    # output
    print(f"{Solution.averageWaitingTime(c1)} is the average waiting time for {c1}")
    print(f"{Solution.averageWaitingTime(c2)} is the average waiting time for {c2}")