struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include <unordered_map>
#include <vector>
using std::vector;
using std::unordered_map;
class Solution {
public:
    TreeNode* buildHelper(unordered_map<int,int>& in_index, vector<int>& pre, vector<int>& in, int pre_left, int pre_right, int in_left, int in_right){
        if(pre_left > pre_right) return nullptr;
        int pre_root_index = pre_left;
        int in_root_index = in_index[pre[pre_root_index]];
        TreeNode* subtree_root = new TreeNode(pre[pre_root_index]);

        int left_subtree_size = in_root_index - in_left;
        // 递归遍历左子树
        subtree_root->left = buildHelper(in_index, pre, in, pre_left + 1, pre_left + left_subtree_size, in_left, in_root_index - 1);
        subtree_root->right = buildHelper(in_index, pre, in, pre_left + left_subtree_size + 1, pre_right, in_root_index + 1, in_right);
        return subtree_root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        std::unordered_map<int, int> in_index;
        int n = preorder.size();
        for(int i = 0; i < n; ++i){
            in_index[inorder[i]] = i;
        }
        return buildHelper(in_index, preorder, inorder, 0, n - 1, 0, n -1);
    }
};