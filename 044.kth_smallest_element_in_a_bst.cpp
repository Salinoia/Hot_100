struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <stack>
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        // bst特性，最小的节点一定位于最“左”侧；
        // 若直接寻找第k小的节点，可以考虑层序遍历再排序
        // 但此时二叉树是二叉搜索树，可以利用搜索树特性，则遍历顺序一定是左中右的中序遍历，这样的结果数组就直接是排序完毕的
        std::stack<TreeNode*> st;
        TreeNode* cur = root;
        if(!root) return 0; 
        while(root || !st.empty()){
            while(cur){
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            --k;
            if(k == 0)  return cur->val;
            cur = cur->right;
        }
        return -1;
    }
};