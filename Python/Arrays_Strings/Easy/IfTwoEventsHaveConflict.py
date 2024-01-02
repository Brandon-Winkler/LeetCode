from typing import List


class Solution:
    def haveConflict(self, event1: List[str], event2: List[str]) -> bool:
        # if the time at event 2 at the start is less than or equal to the time at event 1 at the end
        # and if the time at event 1 at the start is less than or equal to the time at event 2 at the end
        # then we have an intersection so return true otherwise return false 
        return event2[0] <= event1[1] and event1[0] <= event2[1]
    

# driver program
if __name__ == '__main__':
    # initialize event pairs
    e1 = ["02:00","03:00"]
    e2 = ["01:00","02:00"]
    e3 = ["01:00","02:00"]
    e4 = ["01:20","03:00"]
    e5 = ["10:00","11:00"]
    e6 = ["14:00","15:00"]
    e7 = ["14:13","22:08"]
    e8 = ["02:40","08:08"]
    e9 = ["02:00","03:00"]
    e10 = ["01:00","02:00"]

    # solution class instance
    Solution = Solution()

    # output
    if(Solution.haveConflict(e1,e2)): print(f"There is a conflict with {e1} and {e2}")
    else: print(f"There is no conflict between {e1} and {e2}")

    if(Solution.haveConflict(e3,e4)): print(f"There is a conflict with {e3} and {e4}")
    else: print(f"There is no conflict between {e3} and {e4}")

    if(Solution.haveConflict(e5,e6)): print(f"There is a conflict with {e5} and {e6}")
    else: print(f"There is no conflict between {e5} and {e6}")

    if(Solution.haveConflict(e7,e8)): print(f"There is a conflict with {e7} and {e8}")
    else: print(f"There is no conflict between {e7} and {e8}")

    if(Solution.haveConflict(e9,e10)): print(f"There is a conflict with {e9} and {e10}")
    else: print(f"There is no conflict between {e9} and {e10}")