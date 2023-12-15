#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> sortArray(std::vector<int>& nums) {
        if(nums.size() <= 1){
            return nums;
        }

        int middle = nums.size() / 2;

        std::vector<int> left(nums.begin(), nums.begin() + middle);
        std::vector<int> right(nums.begin() + middle, nums.end());

        left = sortArray(left);
        right = sortArray(right);

        return merge(left, right);
    }

    std::vector<int> merge(const std::vector<int>& left, const std::vector<int>& right) {
        std::vector<int> sortedResult;
        int leftIndex = 0;
        int rightIndex = 0;

        while(leftIndex < left.size() && rightIndex < right.size()){
            if(left[leftIndex] < right[rightIndex]){
                sortedResult.push_back(left[leftIndex]);
                leftIndex++;
            }
            else{
                sortedResult.push_back(right[rightIndex]);
                rightIndex++;
            }
        }
        while(leftIndex < left.size()){
            sortedResult.push_back(left[leftIndex]);
            leftIndex++;
        }
        while(rightIndex < right.size()){
            sortedResult.push_back(right[rightIndex]);
            rightIndex++;
        }
        return sortedResult;
    }
};

// Utility fuction to print vector
void printVector(std::vector<int> v) {
    std::cout<<"[";
    for(int i=0;i<v.size();++i){
        std::cout<<" "<<v[i]<<" ";
    }
    std::cout<<"]"<<'\n';
}

int main(){
    // initialize vector
    std::vector<int> vec = {44,5,32,32,57,10,11,2,-1,-2,-13,99,88,65,65,65,7,0,1};

    // solution class instance
    Solution Solution;
    std::vector<int> sortedVec = Solution.sortArray(vec);

    //output
    std::cout<<"Before merge sort: "<<'\n';
    printVector(vec);
    std::cout<<"After merge sort: "<<'\n';
    printVector(sortedVec);

    return 0;
}