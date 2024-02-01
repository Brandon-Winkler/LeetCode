from typing import List


class Solution:
    def numSpecial(self, mat: List[List[int]]) -> int:
        ans = 0                                 # set answer variable to 0

        for row in mat:                         # loop through matrix rows
            if(row.count(1) == 1):              # if there is only one 1 in the row then
                col_idx = row.index(1)          # save the index of where the 1 is
                count = 0                       # set a count to zero
                for r in range(len(mat)):       # loop through all rows in the matrix to check each column
                    if(mat[r][col_idx] == 1):   # if we find an index with a one
                        count += 1              # then add the count
                    if(count > 1):              # if the count becomes greater than one 
                        count -= count          # reseet the count and break
                        break
                ans += count                    # add the current count to the index
        
        return ans

# utility function for printing a matrix
def printMatrix(mat: List[List[int]]) -> None:
    matrix_str = ""
    for row in mat:
        matrix_str += " ".join(map(str, row)) + "\n"
    return matrix_str


# driver program
if __name__ == '__main__':
    #initialize matrices
    m1 = [[1,0,0],[0,0,1],[1,0,0]]
    m2 = [[1,0,0],[0,1,0],[0,0,1]]
    m3 = [[1,0,0],[0,0,1],[1,0,0]]
    m4 = [[0,0,1,0],[0,0,0,0],[0,0,0,0],[0,1,0,0]]

    # solution class instance
    Solution = Solution()

    # output
    print(f"The number of special positions for:\n{printMatrix(m1)}\n is {Solution.numSpecial(m1)}\n")
    print(f"The number of special positions for:\n{printMatrix(m2)}\n is {Solution.numSpecial(m2)}\n")
    print(f"The number of special positions for:\n{printMatrix(m3)}\n is {Solution.numSpecial(m3)}\n")
    print(f"The number of special positions for:\n{printMatrix(m4)}\n is {Solution.numSpecial(m4)}\n")