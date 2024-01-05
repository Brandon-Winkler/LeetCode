class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        vowels = 'aeiou'
        ans = 0
        count = 0

        for i in range(k):          # count the number of vowels in the initial substring of length k
            if s[i] in vowels:
                count+=1
        
        ans = count                 # set the answer to the count

        for i in range(k, len(s)):  # loop through the rest of the string
            if(s[i-k] in vowels):   # if the letter at the current index minus the length is a vowel then decrement
                count-=1
            if(s[i] in vowels):     # if the letter at the current index is a vowel then increment
                count+=1
            ans = max(ans, count)   # find max between the current and previous count
        return ans                  # return the answer

# driver program
if __name__ == '__main__':
    # initialize strings
    s1 = "abciiidef"
    s2 = "aeiou"
    s3 = "weallloveyou"
    
    # solution class instance
    Solution = Solution()

    #output
    print(f"The max vowels from every substring of length 3 in {s1} is {Solution.maxVowels(s1,3)}")
    print(f"The max vowels from every substring of length 2 in {s2} is {Solution.maxVowels(s2,2)}")
    print(f"The max vowels from every substring of length 7 in {s3} is {Solution.maxVowels(s3,7)}")