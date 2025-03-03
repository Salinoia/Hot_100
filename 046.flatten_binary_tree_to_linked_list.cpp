struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include <vector>
class Solution1 {
public:
    void flatten(TreeNode* root){
        TreeNode* curr = root;
        while(curr){
            if(curr->left){
                TreeNode* next = curr->left;
                TreeNode* pre = next; 
                while(pre->right){
                    pre = pre->right;
                }
                pre->right = curr->right;
                curr->left = nullptr;
                curr->right = next;
            }
            curr = curr->right;
        }
        return;
    }
};

class Solution2 {
public:
    // 使用辅助的物理空间，空间复杂度为O(N)
    void preorderTraversal(std::vector<TreeNode*>& res, TreeNode* node){
        if(node ==nullptr) return;
        res.emplace_back(node);
        preorderTraversal(res, node->left);
        preorderTraversal(res, node->right);
    }
    void flatten(TreeNode* root) {
        if(root == nullptr) return;
        std::vector<TreeNode*> res;
        preorderTraversal(res, root);
        for(int i = 1; i < res.size(); ++i){
            TreeNode* prev = res[i - 1], *curr = res[i];
            prev->left = nullptr;
            prev->right = curr;
        }
        return;
    }
};