from typing import List


class Solution:
    def isPrefixString(self, s: str, words: List[str]) -> bool:
        string = ""                         # create string variable to check against s

        for i in words:                     # loop through words and add each string to variable
            string += i
            if(string == s): return True    # if we have our prefix before we get to the end return true
        
        return False                        # otherwise return false

# driver program
if __name__ == '__main__':
    # initialize string array pairs
    s1 = "iloveleetcode"
    a1 = ["i","love","leetcode","apples"]
    s2 = "iloveleetcode"
    a2 = ["apples","i","love","leetcode"]
    s3 = "a"
    a3 = ["aa","aaaa","banana"]

    # solution class instance
    Solution = Solution()

    # output
    if(Solution.isPrefixString(s1,a1)): print(f"{s1} is a prefix of {a1}")
    else: print(f"{s1} is not a prefix of {a1}")

    if(Solution.isPrefixString(s2,a2)): print(f"{s2} is a prefix of {a2}")
    else: print(f"{s2} is not a prefix of {a2}")

    if(Solution.isPrefixString(s3,a3)): print(f"{s3} is a prefix of {a3}")
    else: print(f"{s3} is not a prefix of {a3}")