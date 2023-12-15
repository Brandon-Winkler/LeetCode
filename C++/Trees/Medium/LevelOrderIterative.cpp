#include <vector>
#include <queue>
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
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {

        // initialize vector for result and que for BFS
        std::vector<std::vector<int>> res;
        std::queue<TreeNode *> que;

        // if root is null return root
        if(root == nullptr) return res;

        // push root to initialize the queue
        que.push(root);

        // loop through queue
        while(!que.empty()){
            std::vector<int> level; // level holds the variables inside each node of each level
            int levelSize = que.size(); // level size so that we can only push what is in each level

            // loop through the queue "levelSize" times and push back each value into the level subvector
            for(int i=0;i<levelSize;++i){
                TreeNode *node = que.front();
                que.pop();
                if(node != nullptr){
                    level.push_back(node->val);
                    que.push(node->left);
                    que.push(node->right);
                }
            }
            // if the level subvector isn't empty push it onto the result
            if(!level.empty()) res.push_back(level);
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

    // class instance and result
    Solution Solution;
    std::vector<std::vector<int>> result = Solution.levelOrder(root);

     // output
    std::cout<<"Level Order Iterative solution: "<<"\n";
    for(const std::vector<int>& level : result){
        for(int value : level){
            std::cout<<value<< " ";
        }
        std::cout<<'\n';
    }

    return 0;
}
