from typing import List


class Solution:
    def checkValid(self, matrix: List[List[int]]) -> bool:
        n = len(matrix)                                                 # set length of matrix to constant since it will always be a square matrix

        for row,col in zip(matrix, zip(*matrix)):                       # loop through the matrix rows and columns
            if(len(set(row)) != n or len(set(col)) != n): return False  # if we have a row or col whose set isn't equal to the constant return false

        return True                                                     # otherwise return true


# driver program
if __name__ == '__main__':
    # initialize matrices
    m1 = [
        [1,2,3],
        [3,1,2],
        [2,3,1]
    ]

    m2 = [
        [1,1,1],
        [1,2,3],
        [1,2,3]
    ]

    #solution class instance
    Solution = Solution()

    # output
    if(Solution.checkValid(m1)): print(f"{m1} is a valid matrix")
    else: print(f"{m1} is not a valid matrix")

    if(Solution.checkValid(m2)): print(f"{m2} is a valid matrix")
    else: print(f"{m2} is not a valid matrix")