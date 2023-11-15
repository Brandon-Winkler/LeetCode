#include<iostream>
#include<stack>
using namespace std;

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
    int goodNodes(TreeNode* root) {
        int count = 0;                                                          // count to keep track of good nodes

        stack<pair<TreeNode*,int>> stk;                                         // stack to traverse through tree and track current max
        stk.push({root,root->val});                                             // push root node and root value to start traversal

        while(!stk.empty()){                                                    // loop through tree
            auto [cur,maxSoFar] = stk.top();                                    // variables to process current node and assign current value to current max 
            stk.pop();                                                          // pop stack to continue traversal

            if(cur->val >= maxSoFar) ++count;                                   // if the current value is greater than or equal to current max increase count
            if(cur->left) stk.push({cur->left, max(maxSoFar,cur->val)});        // push left node and max between current value and current max
            if(cur->right) stk.push({cur->right, max(maxSoFar,cur->val)});      // push right node and max between current value and current max
        }
        return count;
    }
};

// Utility function to create a binary tree for testing
TreeNode* createTreeNode(int val) {
    return new TreeNode(val);
}

// driver program
int main(){
    // initialize trees
    TreeNode *root=createTreeNode(5);
    root->right=createTreeNode(10);
    root->left=createTreeNode(0);
    root->left->left=createTreeNode(-1);
    root->left->right=createTreeNode(2);
    root->left->right->left=createTreeNode(1);
    root->right->left=createTreeNode(6);
    root->right->left->right=createTreeNode(7);
    root->right->right=createTreeNode(12);

    // solution class instance
    Solution Solution;

    // output
    cout<<"The number of good nodes in the tree is "<<Solution.goodNodes(root)<<'\n';
    return 0;
}