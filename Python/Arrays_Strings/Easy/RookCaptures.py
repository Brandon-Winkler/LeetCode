from typing import List


class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        cap,row,col = 0,0,0                     # create variables for captures, rows and columns

        for r in range(len(board)):             # loop to find the rooks index
            for c in range(len(board[0])):
                if("R" in board[r][c]):
                    row = r
                    col = c
                    break
        
        for r in range(row-1,-1,-1):            # go up the rows until you get to a bishop or a pawn
            if(board[r][col] == "B"):           # if you find a bishop then we cannot go further
                break
            elif(board[r][col] == "p"):         # if you find a pawn then add it to captures and break
                cap += 1
                break
        
        for r in range(row+1,8):                # go down the rows until you get to a bishop or a pawn
            if(board[r][col] == "B"):
                break
            elif(board[r][col] == "p"):
                cap += 1
                break
        
        for c in range(col-1,-1,-1):            # go down the columns until you get to a bishop or a pawn
            if(board[row][c] == "B"):
                break
            elif(board[row][c] == "p"):
                cap += 1
                break
        
        for c in range(col+1,8):                # go up the columns until you get to a bishop or a pawn
            if(board[row][c] == "B"):
                break
            elif(board[row][c] == "p"):
                cap += 1
                break
        
        return cap                              # return the number of captures
    

# utility function for printing a matrix
def printMatrix(mat: List[List[int]]) -> None:
    matrix_str = ""
    for row in mat:
        matrix_str += " ".join(map(str, row)) + "\n"
    return matrix_str


# driver program
if __name__ == '__main__':
    #initialize boards
    b1 = [
        [".",".",".",".",".",".",".","."],
        [".",".",".","p",".",".",".","."],
        [".",".",".","R",".",".",".","p"],
        [".",".",".",".",".",".",".","."],
        [".",".",".",".",".",".",".","."],
        [".",".",".","p",".",".",".","."],
        [".",".",".",".",".",".",".","."],
        [".",".",".",".",".",".",".","."]
    ]

    b2 = [
        [".",".",".",".",".",".",".","."],
        [".","p","p","p","p","p",".","."],
        [".","p","p","B","p","p",".","."],
        [".","p","B","R","B","p",".","."],
        [".","p","p","B","p","p",".","."],
        [".","p","p","p","p","p",".","."],
        [".",".",".",".",".",".",".","."],
        [".",".",".",".",".",".",".","."]
    ]

    b3 = [
        [".",".",".",".",".",".",".","."],
        [".",".",".","p",".",".",".","."],
        [".",".",".","p",".",".",".","."],
        ["p","p",".","R",".","p","B","."],
        [".",".",".",".",".",".",".","."],
        [".",".",".","B",".",".",".","."],
        [".",".",".","p",".",".",".","."],
        [".",".",".",".",".",".",".","."]
    ]

    # initialize class instance
    Solution = Solution()

    # output
    print(f"\nThe number of available captures in\n{printMatrix(b1)}\nis {Solution.numRookCaptures(b1)}")
    print(f"\nThe number of available captures in\n{printMatrix(b2)}\nis {Solution.numRookCaptures(b2)}")
    print(f"\nThe number of available captures in\n{printMatrix(b3)}\nis {Solution.numRookCaptures(b3)}")