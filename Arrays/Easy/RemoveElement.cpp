#include<iostream>
#include<vector>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int p = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] != val){
                nums[p] = nums[i];
                ++p;
            }
        }
        return p;
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

// Driver program
int main(){
    // initialize vectors
    std::vector<int> v1 = {3,4,1,6,6,5,9};
    std::vector<int> v2 = {4,4,8,9,9,3};

    // solution class instance
    Solution Solution;

    std::cout<<"Vectors before removal: "<<'\n';
    std::cout<<"v1 = ";
    printVector(v1);
    std::cout<<"v2 = ";
    printVector(v2);

    //output
    std::cout<<"Number of values not equal to 6 in first vector: "<<Solution.removeElement(v1, 6)<<'\n';
    std::cout<<"Vector one after removal: ";
    printVector(v1);
    std::cout<<"Number of values not equal to 4 in second vector: "<<Solution.removeElement(v2, 4)<<'\n';
    std::cout<<"Vector two after removal: ";
    printVector(v2);

    return 0;
}


