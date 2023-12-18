from typing import List
from itertools import accumulate

class Solution:
    def vowelStrings(self, words: List[str], queries: List[List[int]]) -> List[int]:
        vowels = 'aeiou'                                    # initialize vowels string to check first and last letters in string
        counts = [0]*len(words)                             # initialize counts array to be the same length as words list

        for i, word in enumerate(words):                    # iterate through words list
            if word[0] in vowels and word[-1] in vowels:    # if first and last letters are in vowels string set counts at ith index to one
                counts[i] = 1

        acc = list(accumulate(counts, initial=0))           # create list of prefix sums
        res = []                                            # initialize empty array to store number of strings that have vowels at first and last positions

        for l, r in queries:                                # loop through queries
            res.append(acc[r+1] - acc[l])                   # append the difference of the prefix sum at right position plus one and left position prefix

        return res

# driver program
if __name__ == '__main__':
    # initialize words and queries
    w1 = ["aba","bcb","ece","aa","e"]
    q1 = [[0,2],[1,4],[1,1]]

    w2 = ["a","e","i"]
    q2 = [[0,2],[0,1],[2,2]]

    # solution class instance
    Solution = Solution()

    # output
    print(f"For the first list the number of strings that start and end in a vowel in ranges {q1} are {Solution.vowelStrings(w1,q1)}")
    print(f"For the second list the number of strings that start and end in a vowel in ranges {q2} are {Solution.vowelStrings(w2,q2)}")