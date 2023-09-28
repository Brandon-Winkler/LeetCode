#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> successfulPairs(std::vector<int>& spells, std::vector<int>& potions, long long success) {
        
        // sort the potions for binary search
        std::sort(potions.begin(), potions.end());
        // initialize vector for successfull pairs
        std::vector<int> pairs;

        // loop through spells
        for(int i = 0; i < spells.size(); ++i) {
            // initialize left and right iterators
            int l = 0, 
                r = potions.size() - 1,
                // create index value to keep track of first element greater than or equal to success threshold
                idx = potions.size();
            // begin binary search
            while(l <= r) {
                int m = (r+l) / 2;
                long long spell = spells[i];
                // if the product of the potion and spell at mid are less than threshold search right
                if((potions[m] * spell) < success) {
                    l = m + 1;
                }
                // otherwitse go left and move the index postion to the middle
                else {
                    r = m - 1;
                    idx = m;
                }
            }
            // push the size of the potions array minus the index
            pairs.push_back(potions.size() - idx);
        }
        return pairs;
    }
};

int main() {
    // initialize spells, potions, and success threshold
    std::vector<int> spells = {4,9,2};
    std::vector<int> potions = {3,6,4,5,2,7};
    int threshold = 20;

    // solution class instance
    Solution Solution;
    std::vector<int> result = Solution.successfulPairs(spells,potions,threshold);

    // output;
    std::cout << "The successful pairs for each spell are: [";
    for (int i = 0; i < result.size(); i++)
    {
        std::cout << " " << result[i] << " ";
    }
    std::cout << ']' << '\n';

    return 0;
}