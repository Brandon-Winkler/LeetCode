from typing import List

class Solution:
    def checkDistances(self, s: str, distance: List[int]) -> bool:
        first_occur = {}                                        # first ocurrence map to track when we see the first occurence of a character

        for i,char in enumerate(s):                             # loop through the given string
            if(char not in first_occur): first_occur[char] = i  # if we haven't see n the character yet put it in the map
            else:                                               # otherwise...
                actual_dist = i-first_occur[char]-1             # calculate the actual distance between two occurences
                expected_dist = distance[ord(char) - 97]        # get the expected distance from the distance array
                if(actual_dist != expected_dist): return False  # check if the actual distance matches the expected distance

        return True


# driver program
if __name__ == '__main__':
    # initiialize strings and distances
    s1 = "abaccb"
    d1 = [1,3,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]

    s2 = "aa"
    d2 = [1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]

    # solution class instance
    Solution = Solution()

    # output
    if(Solution.checkDistances(s1,d1)): print(f"{s1} is a well spaced string")
    else: print(f"{s1} is not a well spaced string")

    if(Solution.checkDistances(s2,d2)): print(f"{s2} is a well spaced string")
    else: print(f"{s2} is not a well spaced string")