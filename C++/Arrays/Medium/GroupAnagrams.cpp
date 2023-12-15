#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::vector<std::vector<std::string>>ans;                       // Create a vector of vectors of strings to store the result
        std::unordered_map<std::string, std::vector<std::string>>map;   // Create an unordered_map to associate sorted strings with their original unsorted strings

        for(auto s : strs){                                             // Iterate through each string in the input vector 'strs'
            auto temp = s;                                              // Create a temporary copy of the string
            std::sort(temp.begin(), temp.end());                        // Sort the characters in the temporary string alphabetically
            map[temp].push_back(s);                                     // Use the sorted string as a key in the map and associate it with the original string
        }

        for(auto it : map){                                             // Iterate through each entry in the map
            auto temp = it.second;                                      // Get the vector of original unsorted strings associated with the sorted key
            ans.push_back(temp);                                        // Add this vector to the 'ans' vector, which collects the grouped anagrams
        }
        return ans;
    }
};

void printGroupedAnagrams(const std::vector<std::vector<std::string>>& sol) {
    for(const std::vector<std::string>& group : sol){
        std::cout<<"Anagram Group: ";
        for(const std::string& str : group){
            std::cout << str << " ";
        }
        std::cout<<std::endl;
    }
}

int main() {
    // initialize string array
    std::vector<std::string> strs1 = {"eat", "bat", "tan", "ate", "nat", "tea"};
    std::vector<std::string> strs2 = {"cinema", "iceman", "listen", "silent", "arc", "car", "bored", "robed"};

    // solution class instance
    Solution Solution;

    // solution variables
    std::vector<std::vector<std::string>> sol1 = Solution.groupAnagrams(strs1);
    std::vector<std::vector<std::string>> sol2 = Solution.groupAnagrams(strs2);

    // output
    std::cout<<"Solution 1: "<<'\n';
    printGroupedAnagrams(sol1);
    std::cout<<'\n';
    std::cout<<"Solution 2: "<<'\n';
    printGroupedAnagrams(sol2);
}