from typing import List


class Solution:
    def numSpecial(self, mat: List[List[int]]) -> int:


def printMatrix(mat: List[List[int]]) -> None:
    for row in mat:
        for num in row:
            print(num, end=" ")
        print()


# driver program
if __name__ == '__main__':
    #initialize matrices
    m1 = [[1,0,0],[0,0,1],[1,0,0]]
    m2 = [[1,0,0],[0,1,0],[0,0,1]]
    m3 = [[1,0,0],[0,0,1],[1,0,0]]

    # solution class instance
    Solution = Solution()

    # output
    print(f"The number of special positions for\n{printMatrix(m1)} is {Solution.numSpecial(m1)}\n")
    print(f"The number of special positions for\n{printMatrix(m2)} is {Solution.numSpecial(m2)}\n")
    print(f"The number of special positions for\n{printMatrix(m3)} is {Solution.numSpecial(m3)}\n")