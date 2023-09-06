#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::vector<std::vector<std::string>>ans;
        std::unordered_map<std::string, std::vector<std::string>>mpp;

        for(auto s : strs){
            auto temp = s;
            std::sort(temp.begin(), temp.end());
            mpp[temp].push_back(s);
        }

        for(auto it : mpp){
            auto temp = it.second;
            ans.push_back(temp);
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