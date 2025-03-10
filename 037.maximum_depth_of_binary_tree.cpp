struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <queue>
class Solution {
public:
    int maxDepth(TreeNode* root) {
        std::queue<TreeNode*> que;
        int depth = 0;
        if(root == nullptr) return 0;

        que.push(root);
        while(!que.empty()){
            int size = que.size();
            depth++;
            for(int i = 0; i < size; ++i){
                TreeNode* node = que.front();
                que.pop();
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
        }
        return depth;
    }
};