from typing import List


class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        # set answer array for output
        ans = []
        # initialize stack and push first node to traverse graph
        stk = []
        stk.append((0,[0]))
        # begin dfs
        while(len(stk) > 0):
            # get current node and current path
            node,path = stk.pop()
            # if we reached the end of path then append path to answer output
            if(node == len(graph)-1): ans.append(path)
            # if the current node has neighbors then push neighbors and corresponding paths for them onto stack
            stk.extend((n,path + [n]) for n in graph[node])
        
        return ans

# driver program
if __name__ == '__main__':
    # initialize graphs
    g1 = [[1,2],[3],[3],[]]
    g2 = [[4,3,1],[3,2,4],[3],[4],[]]

    # solution class instance
    Solution = Solution()

    # output
    print(f"{Solution.allPathsSourceTarget(g1)} are all the paths from nodes 0 to {len(g1)-1}.")
    print(f"{Solution.allPathsSourceTarget(g2)} are all the paths from nodes 0 to {len(g2)-1}.")