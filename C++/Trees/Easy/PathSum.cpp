#include<stack>
#include<iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        std::stack<std::pair<TreeNode*, int>> stk;                              // initialize stack of node and sum pairs to backtrack

        stk.push({root, 0});                                                    // begin dfs by pushing root and 0 onto stack

        if(stk.top().first == nullptr) return 0;                                // if there is no root return false

        while(!stk.empty()){                                                    // loop while there are still nodes to traverse
            TreeNode* node = stk.top().first;                                   // initialize variable to keep track of current node on stack
            int curSum = stk.top().second;                                      // initialize variable to keep track of current sum on stack
            stk.pop();                                                          // pop to mark that we have seen that node
            curSum += node->val;                                                // add current node value to current sum to update sum
            if(!node->left && !node->right && curSum == targetSum) return 1;    // if the sum matches the target and we are at a leaf then return true
            if(node->right) stk.push({node->right, curSum});                    // otherwise push right node and current sum onto the stack
            if(node->left) stk.push({node->left, curSum});                      // and push left node and current sum onto the stack
        }
        return 0;
    }
};

// Utility function to create a binary tree for testing
TreeNode* createTreeNode(int val) {
    return new TreeNode(val);
}

// driver program
int main(){
    // initialize tree
    TreeNode* root = createTreeNode(5);
    root->right = createTreeNode(10);
    root->left = createTreeNode(0);
    root->left->left = createTreeNode(-1);
    root->left->right = createTreeNode(2);
    root->left->right->left = createTreeNode(1);
    root->right->left = createTreeNode(6);
    root->right->left->right = createTreeNode(7);
    root->right->right = createTreeNode(12);

    // solution class instance
    Solution Solution;

    // intialize target variables
    int t1 = 28;
    int t2 = 4;
    int t3 = 9;

    // initialize boolean solutions
    bool target1 = Solution.hasPathSum(root, t1);
    bool target2 = Solution.hasPathSum(root, t2);
    bool target3 = Solution.hasPathSum(root, t3);

    //outputs
    if(target1) std::cout<<"The tree has a path sum of "<<t1<<'\n';
    else std::cout<<"The tree has no path sum of "<<t1<<'\n';

    if(target2) std::cout<<"The tree has a path sum of "<<t2<<'\n';
    else std::cout<<"The tree has no path sum of "<<t2<<'\n';

    if(target3) std::cout<<"The tree has a path sum of "<<t3<<'\n';
    else std::cout<<"The tree has no path sum of "<<t3<<'\n';

    return 0;
}
