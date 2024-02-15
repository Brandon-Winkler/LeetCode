from typing import Optional, List


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:



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
    root1 = TreeNode(3)
    root1.left = TreeNode(9)
    root1.right = TreeNode(20)
    root1.right.left = TreeNode(15)
    root1.right.right = TreeNode(7)

    root2 = TreeNode(5)
    root2.left = TreeNode(10)
    root2.right = TreeNode(21)
    root2.left.left = TreeNode(18)
    root2.left.right = TreeNode(3)

    # solution class instance
    Solution = Solution()

    # output
    print(f"{Solution.averageOfLevels(root1)} are all the averages for each of the levels in {print_tree(root1)}")
    print(f"{Solution.averageOfLevels(root2)} are all the averages for each of the levels in {print_tree(root2)}")