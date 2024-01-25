class Solution:
    def makeSmallestPalindrome(self, s: str) -> str:
        l = 0                               # make left pointer               
        r = len(s)-1                        # make right pointer
        s_list = list(s)                    # turn string into list to make mutable

        while(l < r):                       # loop until left is greater than or equal to right
            if(s_list[l] > s_list[r]):      # if left char is greater change it to right char
                s_list[l] = s_list[r]
            elif(s_list[l] < s_list[r]):    # if left char is less change right char to left char
                s_list[r] = s_list[l]
            l+=1                            # increment left
            r-=1                            # decrement right

        return "".join(s_list)

# driver program
if __name__ == '__main__':
    #initialize strings
    s1 = "egcfe"
    s2 = "abcd"
    s3 = "seven"

    # solution class instance
    Solution = Solution()

    #output
    print(f"The minimum number of operations to make {s1} a palindrome is {Solution.makeSmallestPalindrome(s1)}")
    print(f"The minimum number of operations to make {s2} a palindrome is {Solution.makeSmallestPalindrome(s2)}")
    print(f"The minimum number of operations to make {s3} a palindrome is {Solution.makeSmallestPalindrome(s3)}")