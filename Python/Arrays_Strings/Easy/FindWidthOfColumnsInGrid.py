from typing import List

class Solution:
    def findColumnWidth(self, grid: List[List[int]]) -> List[int]:
        # initialize output list
        ans = []
        # loop through grid column by column
        for c in range(len(grid[0])):
            # set max to initially be the length of the first digit in the column
            mx = len(str(grid[0][c]))
            for r in range(len(grid)):
                # if the max is less than the length of the current digit then set max to be the length of the current digit
                if(mx < len(str(grid[r][c]))): mx = len(str(grid[r][c]))
            # append max of column to output list
            ans.append(mx)

        return ans
    
# driver program
if __name__ == '__main__':
    # initialize grids
    g1 = [[1],[22],[333]]
    g2 = [[-15,1,3],[15,7,12],[5,6,-2]]
    g3 = [[15,133,3],[15,73,12],[5,63,-2]]

    # solution class instance
    Solution = Solution()

    # output
    print(f"For {g1} each column has a maximum width of {Solution.findColumnWidth(g1)}")
    print(f"For {g2} each column has a maximum width of {Solution.findColumnWidth(g2)}")
    print(f"For {g3} each column has a maximum width of {Solution.findColumnWidth(g3)}")