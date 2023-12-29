from typing import List


class Solution:
    def tictactoe(self, moves: List[List[int]]) -> str:
        n = 3                                                       # set constant to 3
        rows, cols = [0]*n, [0]*n                                   # set rows and cols to lists of 3 ints
        diag1 = diag2 = 0                                           # set 2 diagonals to 0

        for i, (r,c) in enumerate(moves):                           # loop through moves to add or subtract 1 in rows and cols
            sign = 1 if i%2 == 0 else -1                            # if the index is even then add 1 otherwise subtract 1
            rows[r] += sign                                         # add or subtract 1 in rows
            cols[c] += sign                                         # add or subtract 1 in cols
            if(r == c): diag1 += sign                               # if the row index and col index match then we are in the first diagonal so add or subtact 1
            if(r+c == n-1): diag2 += sign                           # if the sum of the row and col indices are equal to the constant minus 1 then we are in the second diagonal so add or subtract 1
            if(                                                     # if the absolute value in any row, col, or diagonal are 3
                abs(rows[r]) == n or 
                abs(cols[c]) == n or 
                abs(diag1) == n or 
                abs(diag2) == n
            ):
                return 'A' if sign == 1 else 'B'                    # then return A if the current sign is positive otherwise return B

        return "Draw" if len(moves) == 9 else 'Pending'             # if the length of moves is 9 then we have a draw otherwise the game isn't finished 
    

# driver program
if __name__ == '__main__':
    # initialize moves
    m1 = [[0,0],[2,0],[1,1],[2,1],[2,2]]
    m2 = [[0,0],[1,1],[0,1],[0,2],[1,0],[2,0]]
    m3 = [[0,0],[1,1],[2,0],[1,0],[1,2],[2,1],[0,1],[0,2],[2,2]]
    m4 = [[0,2],[2,0],[0,1],[2,1]]

    # solution class instance
    Solution = Solution()

    #output
    print(f"The winner of {m1} is {Solution.tictactoe(m1)}")
    print(f"The winner of {m2} is {Solution.tictactoe(m2)}")
    print(f"The winner of {m3} is {Solution.tictactoe(m3)}")
    print(f"The winner of {m4} is {Solution.tictactoe(m4)}")