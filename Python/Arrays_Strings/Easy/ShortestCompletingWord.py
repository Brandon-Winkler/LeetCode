from typing import List


class Solution:
    def shortestCompletingWord(self, licensePlate: str, words: List[str]) -> str:


# driver program
if __name__ == '__main__':
    #initialize license plates and words pairs
    l1 = "1s3 PSt"
    w1 = ["step","steps","stripe","stepple"]
    l2 = "1s3 456"
    w2 = ["looks","pest","stew","show"]

    # solution class instance
    Solution = Solution()

    # output
    print(f"The shortest word that can be made from {l1} and {w1} is {Solution.shortestCompletingWord(l1,w1)}")
    print(f"The shortest word that can be made from {l2} and {w2} is {Solution.shortestCompletingWord(l2,w2)}")