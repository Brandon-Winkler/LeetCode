from collections import defaultdict
from typing import List

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        rows = defaultdict(set)                                 # create a dictionary of row numbers with empty sets as keys
        cols = defaultdict(set)                                 # create a dictionary of column numbers with empty sets as keys
        squares = defaultdict(set)                              # create a dictionary of squares with empty sets as keys
        
        for r in range(len(board)):                             # loop through rows and columns
            for c in range(len(board[0])):
                if(board[r][c] == "."): continue                # if we come across a "." then do nothing
                if(                                             # return false if...
                    board[r][c] in rows[r] or                   # the value at coordinate is in the set for the associated row
                    board[r][c] in cols[c] or                   # the value at coordinate is in the set for the associated column
                    board[r][c] in squares[(r // 3, c // 3)]    # the value at coordinate is in the set for the associated square
                ):
                    return False
                rows[r].add(board[r][c])                        # otherwise add the value at coordinate to the associated row set
                cols[c].add(board[r][c])                        # otherwise add the value at coordinate to the associated column set
                squares[(r // 3, c // 3)].add(board[r][c])      # otherwise add the value at coordinate to the associated square set
        return True

# driver program
if __name__ == '__main__':
    # initialize boards
    b1 = [["5","3",".",".","7",".",".",".","."]
         ,["6",".",".","1","9","5",".",".","."]
         ,[".","9","8",".",".",".",".","6","."]
         ,["8",".",".",".","6",".",".",".","3"]
         ,["4",".",".","8",".","3",".",".","1"]
         ,["7",".",".",".","2",".",".",".","6"]
         ,[".","6",".",".",".",".","2","8","."]
         ,[".",".",".","4","1","9",".",".","5"]
         ,[".",".",".",".","8",".",".","7","9"]]
    
    b2 = [['.', '.', '.', '1', '4', '.', '.', '2', '.'],
          ['.', '.', '6', '.', '.', '.', '.', '.', '.'],
          ['.', '.', '.', '.', '.', '.', '.', '.', '.'],
          ['.', '.', '1', '.', '.', '.', '.', '.', '.'],
          ['.', '6', '7', '.', '.', '.', '.', '.', '9'],
          ['.', '.', '.', '.', '.', '.', '8', '1', '.'],
          ['.', '3', '.', '.', '.', '.', '.', '.', '6'],
          ['.', '.', '.', '.', '.', '7', '.', '.', '.'],
          ['.', '.', '.', '5', '.', '.', '.', '7', '.']]
    
    b3 = [['.', '.', '.', '.', '2', '.', '.', '9', '.'],
          ['.', '.', '.', '.', '6', '.', '.', '.', '.'],
          ['7', '1', '.', '.', '7', '5', '.', '.', '.'],
          ['.', '7', '.', '.', '.', '.', '.', '.', '.'],
          ['.', '.', '.', '.', '8', '3', '.', '.', '.'],
          ['.', '.', '8', '.', '.', '7', '.', '6', '.'],
          ['.', '.', '.', '.', '.', '2', '.', '.', '.'],
          ['.', '1', '.', '2', '.', '.', '.', '.', '.'],
          ['.', '2', '.', '.', '3', '.', '.', '.', '.']]
    
    # solution class instance
    Solution = Solution()

    # output
    if Solution.isValidSudoku(b1):
        print("Board one is a valid board")
    else:
        print("Board one isn't a valid board")

    if Solution.isValidSudoku(b2):
        print("Board two is a valid board")
    else:
        print("Board two isn't a valid board")
    
    if Solution.isValidSudoku(b3):
        print("Board three is a valid board")
    else:
        print("Board three isn't a valid board")