struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

#include <vector>
class Solution1{
public:
    void traversal(std::vector<int>& res, TreeNode* node){
        if(node == nullptr) return;
        traversal(res, node->left);
        res.push_back(node->val);
        traversal(res, node->right);
    }
    std::vector<int> inorderTraversal(TreeNode* root){
        std::vector<int> res;
        traversal(res, root);
        return res;
    }
};

#include <stack>
class Solution2{
public:
    std::vector<int> inorderTraversal(TreeNode* root){
        std::vector<int> res;
        std::stack<TreeNode*> st;
        TreeNode* cur = root;
        while(cur || !st.empty()){
            while(cur){
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            res.push_back(cur->val);
            
            cur = cur->right;
        }
        return res;
    }
};