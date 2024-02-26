from typing import List


class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        cache = {}                                  # create cache to store nodes
        
        def dfs(node):                              # dfs to check each nodes path
            if(node in cache): return cache[node]   # if the current node is in the cache then return the node in cache

            cache[node] = False                     # otherwise assume the node is unsafe
            
            for nei in graph[node]:                 # loop through the neighbors of the current node
                if(not dfs(nei)):                   # perform dfs on each neighbor
                    return False                    # return false if any of the paths for any of the nodes are in the cache
                
            cache[node] = True                      # if all of the paths for each node are safe then set node in cache to true
            
            return cache[node]                      # return boolean value for the node in the cache

        # loop through each node and check if each of their paths are safe, if they are append them to the list
        return [node for node in range(len(graph)) if dfs(node)]


# driver program
if __name__ == '__main__':
    # initialize graphs
    g1: List[List[int]] = [[1,2],[2,3],[5],[0],[5],[],[]]
    g2: List[List[int]] = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
    g3: List[List[int]] = [[],[2],[3,4],[4],[]]

    # solution class instance
    Solution = Solution()

    # output
    print(f"{Solution.eventualSafeNodes(g1)} are the nodes with the safe states in {g1}.")
    print(f"{Solution.eventualSafeNodes(g2)} are the nodes with the safe states in {g2}.")
    print(f"{Solution.eventualSafeNodes(g3)} are the nodes with the safe states in {g3}.")