from typing import List


class Solution:
    def checkXMatrix(self, grid: List[List[int]]) -> bool:
        n = len(grid)                                   # set length of grid to constant since it will always be a square matrix

        for r in range(n):                              # loop through matrix
            for c in range(n):
                if(r == c or r+c == n-1):               # if we are on a diagonal and the value at the index is a 0 return false
                    if(grid[r][c] == 0): return False
                elif(grid[r][c] != 0): return False     # if we are not on a diagonal and the value at the index is not a zero then return false
        
        return True                                     # otherwise return true


# driver program
if __name__ == '__main__':
    # initialize grids
    g1 = [
        [2,0,0,1],
        [0,3,1,0],
        [0,5,2,0],
        [4,0,0,2]
    ]

    g2 = [
        [5,7,0],
        [0,3,1],
        [0,5,0]
    ]

    # solution class instance
    Solution = Solution()

    # output
    if(Solution.checkXMatrix(g1)): print(f"{g1} is an X-matrix")
    else: print(f"{g1} is not an X-matrix")

    if(Solution.checkXMatrix(g2)): print(f"{g2} is an X-matrix")
    else: print(f"{g2} is not an X-matrix")