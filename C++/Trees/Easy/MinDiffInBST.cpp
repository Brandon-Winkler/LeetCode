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
    int minDiffInBST(TreeNode* root) {
        std::stack<TreeNode *> stk; // initialize stack for inorder traversal
        TreeNode *node = root; // pointer to current node

        // previous value and minimum variables to keep track of both
        int prevVal = INT_MIN; 
        int minDiff = INT_MAX;
        
        while(node != nullptr || !stk.empty()) {
            if(node != nullptr) {
                stk.push(node); // push current node onto stack to go back to
                node = node->left; // go left
            }
            else {
                node = stk.top(); // if we go left and become null go back using stack top
                stk.pop(); // pop from the stack to mark already visited
                if (prevVal != INT_MIN) minDiff = std::min(minDiff, node->val - prevVal); // find minimum between current minimum and current previous value
                prevVal = node->val; // previous value will now equal previous nodes value
                node = node->right; // go right
            }
        }
        return minDiff;
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

    // solution class instance
    Solution Solution;

    // output
    std::cout << "The minimum distance between any two nodes in the tree is: " << Solution.minDiffInBST(root) << '\n';
    
    return 0;
}

