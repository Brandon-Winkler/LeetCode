class Solution:
    def numberOfSubstrings(self, s: str) -> int:



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