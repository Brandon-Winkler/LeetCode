#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> replaceElements(std::vector<int>& arr) {
      int n = arr.size(); // set variable to array size
      int maxSoFar = arr[n-1]; // set max variable to back of the array
      arr[n-1] = -1; // set back of array to -1
      
      for(int i=n-2;i>=0;i--){ // set iterator to back of array and increment backwords
        int temp = maxSoFar; // create a temp variable to remember previous max
        if(maxSoFar < arr[i]) maxSoFar = arr[i]; // if the current max is less than value at iterator set max to current value at iterator
        arr[i] = temp; // otherwise set value at iterator to previous max
      }
      return arr;
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
    // initialize vectors
    std::vector<int> first = {17,18,5,4,6,1};
    std::vector<int> second = {400};
    std::vector<int> third = {1,1,5,4,3,2,1,6};

    // solution class instance
    Solution Solution;
    std::vector<int> s1 = Solution.replaceElements(first);
    std::vector<int> s2 = Solution.replaceElements(second);
    std::vector<int> s3 = Solution.replaceElements(third);

    //output
    std::cout<<"Replacing elements in first array: "<<'\n';
    printVector(s1);

    std::cout<<"Replacing elements in second array: "<<'\n';
    printVector(s2);

    std::cout<<"Replacing elements in thrid array: "<<'\n';
    printVector(s3);
    
    return 0;
}