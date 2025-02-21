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
    int getDepth(TreeNode* node, int& res){
        if(node == nullptr) return 0;
        int left = getDepth(node->left, res);
        int right = getDepth(node->right, res);
        res = std::max(res, left + right + 1);
        return std::max(left, right) + 1; 
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 1;
        getDepth(root, res);
        return res - 1;
    }
};