from typing import List

class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        indices = []                                    # create list to indices
        string = list(s)                                # convert string to list to iterate over it
        p_sort = sorted(p)                              # sort p to compare to sorted substring
        l = 0                                           # initialize left side of window

        for r in range(len(p)-1,len(string)):           # loop through string using the length of p-1 as right side of window
            substr = sorted(string[l:r+1])              # create substring from window
            if(substr == p_sort): indices.append(l)     # if substring is eqeal to sorted p then append index of left side to indices list
            l += 1                                      # iterate left side of window
        return indices