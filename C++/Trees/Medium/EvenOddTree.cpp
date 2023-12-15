#include <queue>
#include <iostream>

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
    bool isEvenOddTree(TreeNode* root){
        std::queue<TreeNode *> que; // initialize que for bfs
        que.push(root); // push root to begin bfs
        bool flag = true; // set bool flag to true to keep track of levels

        while(!que.empty()){
            int size = que.size(); // initialize que size variable to loop through current level
            int max = INT_MIN, min = INT_MAX; // initialize min and max variables to see if values in level are descending or ascending
            for(int i=0;i<size;++i){
                TreeNode *node = que.front(); // create a node pointer to keep track of current node
                que.pop(); // pop que to mark node as seen
                if(flag){ // case where we are in an even level
                    if(node->val % 2 == 0) return false;
                    if(max < node->val){ // if max is less than current node value then we are descending
                        max = node->val; // adopt new max as node value to make sure we are still descending
                    } 
                    else{ // otherwise return false
                        return false;
                    }
                }
                if(!flag){ // case where we are in an odd level
                    if(node->val % 2 != 0) return false;
                    if(min > node->val){ // if min is more than current node value then we are ascending
                        min = node->val; // adopt new min as node value to make sure we are still ascending
                    }
                    else{ // otherwise return false
                        return false;
                    }
                }
                // push left and right to continue traversal
                if(node->left != nullptr) que.push(node->left);
                if(node->right != nullptr) que.push(node->right);
            }
            flag = !flag; // reverse flag to keep track of even and odd levels
        }
        return true;
    }
};

// Utility function to create a binary tree for testing
TreeNode* createTreeNode(int val) {
    return new TreeNode(val);
}

int main(){
     // first tree
    TreeNode *root1=createTreeNode(5);
    root1->right=createTreeNode(10);
    root1->left=createTreeNode(0);
    root1->left->left=createTreeNode(-1);
    root1->left->right=createTreeNode(2);
    root1->left->right->left=createTreeNode(1);
    root1->right->left=createTreeNode(6);
    root1->right->left->right=createTreeNode(7);
    root1->right->right=createTreeNode(12);

    // second tree
    TreeNode *root2=createTreeNode(1);
    root2->left=createTreeNode(10);
    root2->right=createTreeNode(4);
    root2->left->left=createTreeNode(3);
    root2->right->left=createTreeNode(7);
    root2->right->right=createTreeNode(9);
    root2->left->left->left=createTreeNode(12);
    root2->left->left->right=createTreeNode(8);
    root2->right->left->left=createTreeNode(6);
    root2->right->right->right=createTreeNode(2);

    // solution class
    Solution Solution;

    // output
    std::cout<<"The first tree isn't even-odd: "<<Solution.isEvenOddTree(root1)<<'\n';
    std::cout<<"The second tree is even-odd: "<<Solution.isEvenOddTree(root2)<<'\n';
    
    return 0;
}