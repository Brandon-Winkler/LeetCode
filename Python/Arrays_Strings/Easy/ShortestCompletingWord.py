from typing import List


class Solution:
    def shortestCompletingWord(self, licensePlate: str, words: List[str]) -> str:
        res = []                                        # create list to hold lower case chars

        for char in licensePlate:                       # loop through the license plate string to append chars to list
            if(char.isalpha()):
                res.append(char.lower())

        i=0                                             # set index i to zero to loop through words list
        while(i < len(words)):
            for c in res:                               # loop through result list to compare chars between result and word
                if(res.count(c) > words[i].count(c)):   # if the count at current char in result is greater than the count of the char in the current word
                    words.pop(words.index(words[i]))    # then pop the index of the current word, decrement i and break to remove all words that don't contain the chars in result list
                    i -= 1      
                    break                               
            i += 1                                      # increment i to keep words that do contain all the characters

        ans = sorted(words, key=len)                    # sort all the words that are left by their length
        return ans[0]                                   # since the first word will always be the smallest and come first then return it

# driver program
if __name__ == '__main__':
    #initialize license plates and words pairs
    l1 = "1s3 PSt"
    w1 = ["step","steps","stripe","stepple"]
    l2 = "1s3 456"
    w2 = ["looks","pest","stew","show"]
    l3 = "GrC8950"
    w3 = ["measure","other","every","base","according","level","meeting","none","marriage","rest"]

    # solution class instance
    Solution = Solution()

    # output
    print(f"The shortest word that can be made from {l1} and {w1} is {Solution.shortestCompletingWord(l1,w1)}")
    print(f"The shortest word that can be made from {l2} and {w2} is {Solution.shortestCompletingWord(l2,w2)}")
    print(f"The shortest word that can be made from {l3} and {w3} is {Solution.shortestCompletingWord(l3,w3)}")