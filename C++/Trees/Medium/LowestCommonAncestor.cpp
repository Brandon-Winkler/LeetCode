#include<iostream>
using namespace std;

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       TreeNode* cur = root;                                                    // current node to traverse through tree                        

        while(true){
            if(p->val < cur->val && q->val < cur->val) cur = cur->left;        // if current value is greater than both p and q value go left
            else if(p->val > cur->val && q->val > cur->val) cur = cur->right;  // if current value is less than both p and q values go right 
            else break;                                                        // break once current is lowest common ancestor
        }
        return cur;
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

    TreeNode* s1 = Solution.lowestCommonAncestor(root, root->right, root->left);
    TreeNode* s2 = Solution.lowestCommonAncestor(root, root->right, root->right->left->right);
    TreeNode* s3 = Solution.lowestCommonAncestor(root, root->left->left, root->left->right->left);

    // output
    cout<<"The lowest common ancestor of 0 and 10 is "<<s1->val<<'\n';
    cout<<"The lowest common ancestor of 7 and 10 is "<<s2->val<<'\n';
    cout<<"The lowest common ancestor of -1 and 1 is "<<s3->val<<'\n';
    return 0;
}