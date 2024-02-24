from typing import List


class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:



# driver program
if __name__ == '__main__':
    # initialize graphs
    g1: List[List[int]] = [[1,2],[2,3],[5],[0],[5],[],[]]
    g2: List[List[int]] = [[1,2,3,4],[1,2],[3,4],[0,4],[]]

    # solution class instance
    Solution = Solution()

    # output
    print(f"{Solution.eventualSafeNodes(g1)} are the nodes with the safe states in {g1}.")
    print(f"{Solution.eventualSafeNodes(g2)} are the nodes with the safe states in {g2}.")