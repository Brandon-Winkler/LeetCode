#include <vector>
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
    std::vector<int> inorderTraversal(TreeNode* root) {
         // create a vector for output and stack to keep track of nodes
        std::vector<int> nodes;
        std::stack<TreeNode *> stk;
        // tree node pointer
        TreeNode *curr = root;
        // if root is null return empty vector
        if(curr == nullptr) return nodes;

        while(curr != nullptr || !stk.empty()) {
            // while current is not null push current node onto stack and got left
            if(curr != nullptr) {
                stk.push(curr);
                curr = curr->left;
            }
            // otherwise set current to stack top to traverse right subtree and push value of stack top to output then pop and go right
            else {
                curr = stk.top();
                nodes.push_back(curr->val);
                stk.pop();
                curr = curr->right;
            }
        }
        return nodes;
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

    // class instance and result
    Solution Solution;
    std::vector<int> res = Solution.inorderTraversal(root);

    // output
    std::cout << "Inorder Iterative solution: [";
    for (int i = 0; i < res.size(); i++)
    {
        std::cout << " " << res[i] << " ";
    }
    std::cout << ']' << '\n';

    return 0;
}