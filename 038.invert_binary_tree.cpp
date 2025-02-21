struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <algorithm>
class Solution {
public:
    void traversal(TreeNode* node){
        if(!node) return;
        std::swap(node->left, node->right);
        traversal(node->left);
        traversal(node->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        std::swap(root->left, root->right);
        invertTree(root->left);// (y)
        // std::swap(root->left, root->right); (n)
        invertTree(root->right);
        //std::swap(root->left, root->right);//(y)
        return root;
    }
};