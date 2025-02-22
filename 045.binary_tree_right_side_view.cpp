
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <vector>
#include <queue>
using std::vector;
class Solution {
public:
    void dfs(TreeNode* node, vector<int>& res, int depth){
        if(!node) return;
        if(depth == res.size()){
            res.push_back(node->val);
        }
        dfs(node->left, res, depth + 1);
        dfs(node->right, res, depth + 1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        dfs(root, res, 0);
        return res;
    }
};