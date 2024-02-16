from typing import Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def findTilt(self, root: Optional[TreeNode]) -> int:


def print_tree(root):
    print("[ ")
    if root:
        print_tree(root.left)
        print(root.val, end=' ')
        print_tree(root.right)
    print("]")


# driver program
if __name__ == '__main__':
    # initialize trees
    root1 = TreeNode(1)
    root1.left = TreeNode(2)
    root1.right = TreeNode(3)

    root2 = TreeNode(4)
    root2.left = TreeNode(2)
    root2.right = TreeNode(9)
    root2.left.left = TreeNode(3)
    root2.left.right = TreeNode(5)
    root2.right.right = TreeNode(7)

    root3 = TreeNode(21)
    root3.left = TreeNode(7)
    root3.right = TreeNode(14)
    root3.left.left = TreeNode(1)
    root3.left.right = TreeNode(1)
    root3.right.left = TreeNode(2)
    root3.right.right = TreeNode(2)
    root3.left.left.left = TreeNode(3)
    root3.left.left.right = TreeNode(3)

    # solution class instance
    Solution = Solution()

    # output
    print(f"The tilt of {print_tree(root1)} is {Solution.findTilt(root1)}.")
    print(f"The tilt of {print_tree(root2)} is {Solution.findTilt(root2)}.")
    print(f"The tilt of {print_tree(root3)} is {Solution.findTilt(root3)}.")