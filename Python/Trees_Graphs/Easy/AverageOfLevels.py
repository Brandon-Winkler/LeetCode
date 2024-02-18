from typing import Optional, List
from queue import deque


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        que = deque()                                           # create que to hold levels
        ans = []                                                # initialize answer for output

        que.append(root)                                        # append root to queue to begin bfs

        while(que):                                             
            levelSize = len(que)                                # create variable to hold the level size
            tot = 0                                             # create variable to hold the total of that level
            for i in range(levelSize):                          # loop through level size
                node = que.popleft()                            # pop and store current node
                tot += node.val                                 # add current nodes total
                if(node.left): que.append(node.left)            # if node has a left child then append to queue to traverse next level
                if(node.right): que.append(node.right)          # if node has a right child then append to queue to traverse next level
            if(levelSize != 0): ans.append(tot/levelSize)       # if level isn't empty then divide level total by level size and append to answer
    
        return ans
    

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
    print(f"{Solution.averageOfLevels(root1)} are all the averages for each of the levels in first tree.")
    print(f"{Solution.averageOfLevels(root2)} are all the averages for each of the levels in second tree.")