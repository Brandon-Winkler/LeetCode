#include <vector>
#include <iostream>

class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        // modulus K to ensure it can't be bigger than the size of the array
        k = k % nums.size();

        std::reverse(nums.begin(), nums.end());
        std::reverse(nums.begin(), nums.begin() + k);
        std::reverse(nums.begin() + k, nums.end());
    }
};

// utility class for printing vector
void printVector(std::vector<int> &vector) {
    for(int i : vector) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
}

int main() {
    // initialize vector
    std::vector<int> vec = {1,2,3,4,5,6,7};

    std::cout << "original vector: ";
    printVector(vec);

    // solution class instance
    Solution Solution;
    Solution.rotate(vec, 4);

    std::cout << "rotated vector: ";
    printVector(vec);
    
    return 0;
}
