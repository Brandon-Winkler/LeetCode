class Solution:
    def partitionString(self, s: str) -> int:
        s_list = list(s)            # convert string to list to iterate
        substr = ""                 # intialize substring to track partitions 
        ans = 1                     # intialize answer variable to 1 to account for last partition
        
        for c in s_list:            # loop through string list
            if(c not in substr):    # if character not in current substring then add it to substring
                substr += c
            else:                   # otherwise add one to answer output and set substring to current character to reset
                ans += 1
                substr = c

        return ans

# driver program
if __name__ == '__main__':
    # initialize strings
    s1 = "abacaba"
    s2 = "ssssss"

    # solution class instance
    Solution = Solution()

    # output
    print(f"The minimum number of unique substrings for string one is {Solution.partitionString(s1)}")
    print(f"The minimum number of unique substrings for string two is {Solution.partitionString(s2)}")