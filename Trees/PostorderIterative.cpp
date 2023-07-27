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

// Utility function to create a binary tree for testing
TreeNode* createTreeNode(int val) {
    return new TreeNode(val);
}

class Solution {
public:
    std::vector<int> postorderTraversal(TreeNode* root) {
        // initialize output and stack to keep track of nodes
        std::vector<int> res;
        std::stack<TreeNode*> stack;
        // initialize stack to keep track of when we have already visited a node
        std::stack<bool> visit;
        // push initial values into both stacks
        stack.push(root);
        visit.push(false);

        while (!stack.empty()) {
            // set tree pointer to root that we pushed to stack
            TreeNode* curr = stack.top();
            // pop stack to mark that we have seen the root
            stack.pop();

            // set bool flag to see if we have visited the node
            bool v = visit.top();
            // pop to make room for more visits
            visit.pop();

            if (curr) {
                // if we have visited the nodes push back the current node value
                if (v) {
                    res.push_back(curr->val);
                } 
                // otherwise push the current node onto the stack and mark that we have seen it
                // then push right and left nodes and mark that we haven't seen them
                else {
                    stack.push(curr);
                    visit.push(true);
                    stack.push(curr->right);
                    visit.push(false);
                    stack.push(curr->left);
                    visit.push(false);
                }
            }
        }
        return res;
    }
};

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
    std::vector<int> res = Solution.postorderTraversal(root);

    // output
    std::cout << "Postorder Iterative solution: [";
    for (int i = 0; i < res.size(); i++)
    {
        std::cout << " " << res[i] << " ";
    }
    std::cout << ']' << '\n';

    return 0;
}