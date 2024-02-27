from typing import List

class Solution:
    def efficientRoads(self, n: int, roads: List[List[int]]) -> bool:


# driver program
if __name__ == '__main__':
    # initialize roads
    r1: List[List[int]] = [[3,0],[0,4],[5,0],[2,1],[1,4],[2,3],[5,2]]
    r2: List[List[int]] = [[0,1],[0,2],[3,4]]
    r3: List[List[int]] = []

    # solution class instance
    Solution = Solution()

    # output
    if(Solution.efficientRoads(r1)): print(f"All of roads in {r1} are efficient.")
    else: print(f"{r1} does not have effifient roads.")

    if(Solution.efficientRoads(r2)): print(f"All of roads in {r2} are efficient.")
    else: print(f"{r2} does not have effifient roads.")
    
    if(Solution.efficientRoads(r3)): print(f"All of roads in {r3} are efficient.")
    else: print(f"{r3} does not have effifient roads.")