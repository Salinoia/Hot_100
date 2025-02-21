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
    TreeNode* pre = nullptr;
    bool isValidBST(TreeNode* node) {
        if(!node) return true;
        bool left = isValidBST(node->left);
        if(pre && pre->val >= node->val) return false;
        pre = node;
        bool right = isValidBST(node->right);
        return left && right;
    }
};