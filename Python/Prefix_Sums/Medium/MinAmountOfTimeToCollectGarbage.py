from typing import List


class Solution:
    def garbageCollection(self, garbage: List[str], travel: List[int]) -> int:
        ans = 0                                 # set answer variable initially to 0 to hold travel times

        m,p,g = False,False,False               # set m,p,g chars to false

        for i in range(len(garbage)-1,-1,-1):   # reverse loop through garbage to find the last instance of each character
            if(not g and "G" in garbage[i]):    # if the char is false and in the current string
                g = True                        # set char to true to mark that we have seen the last instance
                ans += sum(travel[:i])          # add the travel time up to the string with last instance
            if(not m and "M" in garbage[i]):
                m = True
                ans += sum(travel[:i])
            if(not p and "P" in garbage[i]):
                p = True
                ans += sum(travel[:i])
            if(all([m,p,g])): break              # if we have seen all last instances then we have the minimum travel time so break out of loop

        return len("".join(garbage))+ans         # add the travel time to the number of total chars in garbage


# driver program
if __name__ == '__main__':
    # initialize garbage and time
    g1 = ["G","P","GP","GG"]
    t1 = [2,4,3]

    g2 = ["MMM","PGM","GP"]
    t2 = [3,10]

    g3 = ["MGGGP","PPM","P","PPPGMMMPPM","PMGGGM","MMGMMPPPPP","PGGGPM","GGMMPMP","P","GGMPM"]
    t3 = [25,74,10,3,69,34,52,58,1]

    # solution class instance
    Solution = Solution()

    # output
    print(f"The minimum amount of time to collect all garbage from {g1} with a travel time of {t1} is {Solution.garbageCollection(g1,t1)}")
    print(f"The minimum amount of time to collect all garbage from {g2} with a travel time of {t2} is {Solution.garbageCollection(g2,t2)}")
    print(f"The minimum amount of time to collect all garbage from {g3} with a travel time of {t3} is {Solution.garbageCollection(g3,t3)}")