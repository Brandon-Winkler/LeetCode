from typing import List
from math import inf


class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        min_index = inf         # set minimum index to inf initially to compare
        ans = []                # set answer output list

        for i in list1:         # loop through list one
            if(i in list2):     # if the string at the current index is in list two
                min_index = min(min_index, list1.index(i)+list2.index(i))   # then get the minimum between the sum of their respective indices and the current minimum index

        for i in list1:         # loop through list one
            if(i in list2):     # if the string at the current index is in list two
                if(list1.index(i)+list2.index(i) == min_index): # and the sum of their indices is equal to the minimum sum
                    ans.append(i)   # append the string at the current index to output

        return ans

# driver program
if __name__ == '__main__':
    # initialize string array pairs
    s1 = ["Shogun","Tapioca Express","Burger King","KFC"]
    s2 = ["Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"]
    s3 = ["Shogun","Tapioca Express","Burger King","KFC"]
    s4 = ["KFC","Shogun","Burger King"]
    s5 = ["happy","sad","good"]
    s6 = ["sad","happy","good"]

    # solution class instance
    Solution = Solution()

    # output
    print(f"The common strings with the least index sum in {s1} and {s2} are {Solution.findRestaurant(s1,s2)}")
    print(f"The common strings with the least index sum in {s3} and {s4} are {Solution.findRestaurant(s3,s4)}")
    print(f"The common strings with the least index sum in {s5} and {s6} are {Solution.findRestaurant(s5,s6)}")