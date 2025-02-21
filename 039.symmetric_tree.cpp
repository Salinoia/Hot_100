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
    bool comparsion(TreeNode* left, TreeNode* right){
        if(left == nullptr && right == nullptr) return true;
        else if(left && !right) return false;
        else if(!left && right) return false;

        if(left->val != right->val) return false;
        bool outside = comparsion(left->left, right->right);
        bool inside = comparsion(left->right, right->left);
        return outside && inside;
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return false;
        return comparsion(root->left, root->right);
    }
};