#include <stack>
#include <iostream>

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
    int maxDepth(TreeNode* root) {
        // initialize stack with pair data to hold the nodes and depths
        std::stack<std::pair<TreeNode *, int>> stk;
        stk.push({root,1});

        // create result variable to keep track of max
        int res = 0;

        while(!stk.empty()) {
            TreeNode *node = stk.top().first; // create pointer to point to node at the top of the stack
            int depth = stk.top().second; // assign depth to current top of stack
            stk.pop(); // pop from stack to point to next node

            if(node != nullptr) {
                res = std::max(res, depth); // compare the current result to current depth to find max
                stk.push({node->left, depth + 1}); // push left node and increment depth by one
                stk.push({node->right, depth + 1}); // push right node and increment depth by one
            }
        }
        return res;
    }
};

// Utility function to create a binary tree for testing
TreeNode* createTreeNode(int val) {
    return new TreeNode(val);
}

int main() {
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

    // class instance
    Solution Solution;

    // output
    std::cout << "The max depth of the tree is " << Solution.maxDepth(root) << '\n'; 
    
    return 0;
}