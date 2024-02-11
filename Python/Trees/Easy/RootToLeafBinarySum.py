from typing import Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def sumRootToLeaf(self, root: Optional[TreeNode]) -> int:



# function to print tree
def print_tree(root):
    print("[ ")
    if root:
        print_tree(root.left)
        print(root.val, end=' ')
        print_tree(root.right)
    print(" ]")


# driver program
if __name__ == '__main__':
    # initialize trees
    root1 = TreeNode(1)
    root1.left = TreeNode(0)
    root1.right = TreeNode(1)
    root1.left.left = TreeNode(0)
    root1.left.right = TreeNode(1)
    root1.right.left = TreeNode(0)
    root1.right.right = TreeNode(1)

    root2 = TreeNode(0)

    # solution class instance
    Solution = Solution()

    # output
    print(f"The sum of all root to leaf binary numbers in {print_tree(root1)} is  {Solution.sumRootToLeaf(root1)}")
    print(f"The sum of all root to leaf binary numbers in {print_tree(root2)} is  {Solution.sumRootToLeaf(root2)}")