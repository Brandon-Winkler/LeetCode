from typing import List


class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:


# driver program
if __name__ == '__main__':
    # initialize graphs
    g1 = [[1,2],[3],[3],[]]
    g2 = [[4,3,1],[3,2,4],[3],[4],[]]

    # solution class instance
    Solution = Solution()

    # output
    print(f"{Solution.allPathsSourceTarget(g1)} are all the paths from 0 to {len(g1)-1}")
    print(f"{Solution.allPathsSourceTarget(g2)} are all the paths from 0 to {len(g2)-1}")