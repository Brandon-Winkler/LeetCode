from typing import Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def evaluateTree(self, root: Optional[TreeNode]) -> bool:



# driver program
if __name__ == '__main__':
    # initialize trees
    root1 = TreeNode(2)
    root1.left = TreeNode(1)
    root1.right = TreeNode(3)
    root1.right.left = Solution(0)
    root1.right.right = Solution(1)

    root2 = TreeNode(0)

    # solution class instance
    Solution = Solution()

    # output
    if(Solution.evaluateTree(root1)): print(f"This tree has a boolean result of True.")
    else: print(f"This tree has a boolean result of False.")

    if(Solution.evaluateTree(root2)): print(f"This tree has a boolean result of True.")
    else: print(f"This tree has a boolean result of False.")