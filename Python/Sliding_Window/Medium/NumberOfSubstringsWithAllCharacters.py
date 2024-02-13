class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        res = 0                                 # initialize output variable
        last = {"a":-1,"b":-1,"c":-1}           # use hash table to track index of last seen character

        for i,c in enumerate(s):                # enumerate through the string
            if(                                 # if the current character is a,b or c (right side of window)
                c == "a" or 
                c == "b" or 
                c == "c"
            ):
                last[c] = i                     # set the character key in hash table to the current index (left side of window)
            res += 1 + min(last.values())       # add 1 plus the minimum in the hash table values to the output
        
        return res


# driver program
if __name__ == '__main__':
    # initialize strings
    s1 = "abcabc"
    s2 = "aaacb"
    s3 = "abc"

    # solution class instance
    Solution = Solution()

    # output
    print(f"{Solution.numberOfSubstrings(s1)} is the number of substrings containing the characters a, b and c in {s1}.")
    print(f"{Solution.numberOfSubstrings(s2)} is the number of substrings containing the characters a, b and c in {s2}.")
    print(f"{Solution.numberOfSubstrings(s3)} is the number of substrings containing the characters a, b and c in {s3}.")