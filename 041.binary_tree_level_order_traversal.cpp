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
using std::queue;
using std::vector;
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        vector<vector<int>> res;
        if(!root) return res;
        else que.push(root);

        while(!que.empty()){
            int size = que.size();
            vector<int> vec;
            for(int i = 0; i < size; ++i){
                TreeNode* node = que.front();
                vec.emplace_back(node->val);
                que.pop();
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            res.emplace_back(vec);
        }
        return res;
    }
};