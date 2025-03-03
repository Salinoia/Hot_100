struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* node, TreeNode* p, TreeNode* q) {
        // 维护每个节点的父节点的信息进行查询？相当于双向链表里的prev节点？
        // 什么样的遍历方式能维护前向节点信息呢？后序遍历肯定能做到，但这里需要考虑显式维护还是隐式维护节点？
        // 显然，显式维护需要一个哈希表记录每个节点的前向节点，还需要记录每一个节点的路径以找到两个节点的最低深度的交集
        // 如果使用递归则不需要进行交集的判定操作
        if(!node || node == p || node == q) return node;// 确定递归终止条件
        TreeNode* left = lowestCommonAncestor(node->left, p, q); // 在左子树中寻找p或q
        TreeNode* right = lowestCommonAncestor(node->right, p, q); // 右

        if(left && right) return node; // 左右子树皆找到，则此时的node为lca
        return left ? left : right;  // 否则返回找到的那一侧
    }

};
// 如果显式维护前向节点，则需要额外辅助空间
#include <unordered_map>
#include <vector>
#include <algorithm>
void getParentMap(TreeNode* node, std::unordered_map<TreeNode*, TreeNode*>& parent){
    if(!node) return;
    if(node->left){
        parent[node->left] = node;
        getParentMap(node->left, parent);
    }
    if(node->right){
        parent[node->right] = node;
        getParentMap(node->right, parent);
    }
    return;
}
std::vector<TreeNode*> getPath(TreeNode* node, std::unordered_map<TreeNode*, TreeNode*>& parent){
    std::vector<TreeNode*> path;
    while(node){
        path.emplace_back(node);
        node = parent[node];
    }
    reverse(path.begin(), path.end());
    return path;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
    std::unordered_map<TreeNode*, TreeNode*> parents;
    parents[root] = nullptr;
    getParentMap(root, parents);
    
    std::vector<TreeNode*> p_path = getPath(p, parents);
    std::vector<TreeNode*> q_path = getPath(q, parents);

    TreeNode* lca = nullptr;
    int i = 0;

    while(i < p_path.size() && i < q_path.size() && p_path[i] == q_path[i]){
        lca = p_path[i];
        i++;
    }
    return lca;
}