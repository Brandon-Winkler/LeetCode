#include <iostream>
#include <vector>

int binarySearch(std::vector<int>& nums, int target) {
    int lhs = 0, rhs = nums.size() - 1, mid = (nums.size() - 1) / 2;

    while(lhs <= rhs) {
        if(nums[lhs] == target) return lhs;
        if(nums[rhs] == target) return rhs;
        if(nums[mid] == target) return mid;

        if(nums[mid] < target) {
            lhs = mid + 1;
            mid = (rhs+lhs) / 2;
        }

        if(nums[mid] > target) {
            rhs = mid - 1;
            mid = (rhs+lhs) / 2;
        }
    }
    return -1;
}

int main () {

    std::vector<int> vec{-1, 0, 3, 5, 9, 12, 13, 20};
    int num1 = 3, num2 = 13, num3 = 2;

    std::cout << binarySearch(vec, num1) << '\n';
    std::cout << binarySearch(vec, num2) << '\n';
    std::cout << binarySearch(vec, num3) << '\n';

}