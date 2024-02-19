from typing import List


class Solution:
    def averageWaitingTime(self, customers: List[List[int]]) -> float:
        ans = []                                    # initialize answer array to sum up waiting times
        time = 0                                    # keep track of running time

        for i,(start,end) in enumerate(customers):
            if(i == 0):                             # for our first index
                time += start+end                   # we sum the start and end and add it to the running time
                ans.append(time-start)              # append the time of the first index minus the start to answer array
            else:                                   # for subsequent indices
                if(start < time):                   # if the running time is greater than the start
                    time += end                     # add the ending time to running
                    ans.append(time-start)          # append the running time minus the start to the array
                else:                               # if the start time is greater than the running
                    time = start+end                # assign the start plus end to the time
                    ans.append(time-start)          # append the time minus the start

        return sum(ans)/len(customers)              # return the sum of the list divided by the number of customers


# driver program
if __name__ == '__main__':
    # initialize customers times
    c1 = [[1,2],[2,5],[4,3]]
    c2 = [[5,2],[5,4],[10,3],[20,1]]
    c3 = [[2,3],[6,3],[7,5],[11,3],[15,2],[18,1]]

    # solution class instance
    Solution = Solution()

    # output
    print(f"{Solution.averageWaitingTime(c1)} is the average waiting time for {c1}")
    print(f"{Solution.averageWaitingTime(c2)} is the average waiting time for {c2}")
    print(f"{Solution.averageWaitingTime(c3)} is the average waiting time for {c3}")