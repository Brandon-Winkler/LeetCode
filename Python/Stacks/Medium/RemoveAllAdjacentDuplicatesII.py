class Solution:
    def removeDuplicates(self, s: str, k: int) -> str:
        chars = []                                              # create a char stack to track previous characters
        count = []                                              # create a count stack to remember which numbers have which counts so far

        for i in s:                                             # loop through the string
            if(not chars or i != chars[-1]):                    # if the char list is empty or the current char isn't the previous
                chars.append(i)                                 # append current char to list
                count.append(1)                                 # append it's corresponding new count
            elif(i == chars[-1] and count[-1] != k):            # if the current char is the previous char and the current count not equal to K
                count[-1] += 1                                  # then increase current count by one
            if(i == chars[-1] and count[-1] == k):              # if the current char is the previous char and the current count is equal to K
                chars.pop()                                     # pop the previous char from chars
                count.pop()                                     # and pop it's corresponding count
        
        ans = ""                                                # create answer string for output
        ans += "".join([i*j for i,j in zip(chars,count)])       # append all the chars in the list multiplied by their corresponding count to get answer
        return ans


# driver program
if __name__ == '__main__':
    # initialize strings
    s1 = "abcd"
    s2 = "deeedbbcccbdaa"
    s3 = "pbbcggttciiippooaais"

    # solution class instance
    Solution = Solution()

    # output
    print(f"{s1} after removal of all 2 adjacent duplicates is {Solution.removeDuplicates(s1,2)}")
    print(f"{s2} after removal of all 3 adjacent duplicates is {Solution.removeDuplicates(s2,3)}")
    print(f"{s3} after removal of all 2 adjacent duplicates is {Solution.removeDuplicates(s3,2)}")