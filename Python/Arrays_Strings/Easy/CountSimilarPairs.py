from typing import List
from math import comb


class Solution:
    def similarPairs(self, words: List[str]) -> int:
        table = {}                      # create a hash table to track occurences of similar strings       
        ans = 0                         # initialize answer output

        for w in words:                 # loop through words array
            word = frozenset(w)         # convert each word into a set to reference for duplicates
            if(word not in table):      # if we don't have a duplicate put the set into the table
                table[word] = 1         
            else:                       # otherwise add 1 to the frequency of the set
                table[word] += 1
        # use combinatorics to count unique duplicates and sum them into answer
        ans = sum(comb(val,2) for val in table.values()) 
        return ans

# driver program
if __name__ == '__main__':
    # initialize string arrays
    w1 = ["aba","aabb","abcd","bac","aabc"]
    w2 = ["aabb","ab","ba"]
    w3 = ["nba","cba","dba"]

    # solution class instance
    Solution = Solution()

    # output
    print(f"The number of pairs of similar strings in {w1} is {Solution.similarPairs(w1)}")
    print(f"The number of pairs of similar strings in {w2} is {Solution.similarPairs(w2)}")
    print(f"The number of pairs of similar strings in {w3} is {Solution.similarPairs(w3)}")