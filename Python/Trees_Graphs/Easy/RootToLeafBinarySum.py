from typing import Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def sumRootToLeaf(self, root: Optional[TreeNode]) -> int:
        ans = 0
        
        # initialize stack to traverse tree and remember previous paths
        stk = []
        stk.append([root, ""])

        # dfs on tree
        while(len(stk) > 0):
            # create node and path variables to track current node and current path
            node, path = stk.pop()
            # set current variable to value in node and cast to a string so that we can convert to decimal later
            curr = str(node.val)
            # concatinate current string to path
            path += curr
            # if we get to a leaf node then cast to decimal and add to answer
            if(not node.left and not node.right): ans += int(path,2)
            # otherwise push left or right node onto stack with that nodes current path
            if(node.right): stk.append([node.right, path])
            if(node.left): stk.append([node.left, path])
        
        return ans


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
    print(f"The sum of all root to leaf binary numbers in tree one is {Solution.sumRootToLeaf(root1)}.")
    print(f"The sum of all root to leaf binary numbers in tree two is {Solution.sumRootToLeaf(root2)}.")