from typing import List


class Solution:
    def construct2DArray(self, original: List[int], m: int, n: int) -> List[List[int]]:
        ans = []                                    # create answer variable to build matrix                                 

        for i in range(0,len(original),n):          # loop through original array and step by n to build matrix
            ans.append(original[i:i+n])             # append all values from index to n plus index

        if(len(ans) == m and len(ans[0]) == n):     # if the size of our matrix rows and columns match m and n then return the answer
            return ans

        return []                                   # otherwise return an empty array

# driver program
if __name__ == '__main__':
    # initialize arrays
    a1 = [1,2,3,4]
    a2 = [1,2,3]
    a3 = [1,2]

    # solution class instance
    Solution = Solution()

    # output
    print(f"The a 2x2 2D array constructed from {a1} is {Solution.construct2DArray(a1,2,2)}")
    print(f"The a 1x3 2D array constructed from {a2} is {Solution.construct2DArray(a2,1,3)}")
    print(f"The a 1x1 2D array constructed from {a3} is {Solution.construct2DArray(a1,1,1)}")