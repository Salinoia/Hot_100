struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 递归
#include <climits>

class Solution1{
public:
    int maxPathSum(TreeNode* root){
        return dfs(root);
    }
private:
    int dfs(TreeNode* node){
        if(!node) return 0;
        int left_contribution = std::max(dfs(node->left), 0);
        int right_contribution = std::max(dfs(node->right), 0); 
        
        max_sum  = std::max(max_sum, node->val + left_contribution + right_contribution);
        
        return max_sum;
    }
    int max_sum = INT_MIN;
};


// 暴力法
#include <unordered_map>
#include <vector>
#include <unordered_set>
using std::unordered_set;
using std::unordered_map;
using std::vector;

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if (!root) return 0;
        
        // 1. 建立父节点映射和前缀和映射
        unordered_map<TreeNode*, TreeNode*> parent;
        unordered_map<TreeNode*, int> prefixSum;
        vector<TreeNode*> nodes;
        
        parent[root] = nullptr;
        prefixSum[root] = root->val;
        nodes.push_back(root);
        
        // 递归收集所有节点并建立映射
        getNodesAndParents(parent, prefixSum, nodes, root);
        
        int max_sum = INT_MIN;
        
        // 2. 双重遍历所有节点对
        for (auto u : nodes) {
            for (auto v : nodes) {
                // 计算u和v之间的路径和
                TreeNode* lca = findLCA(u, v, parent);
                int current_sum = prefixSum[u] + prefixSum[v] - 2 * prefixSum[lca] + lca->val;
                
                // 更新最大值
                max_sum = std::max(max_sum, current_sum);
            }
            // 单独节点情况（路径只有自己）
            max_sum = std::max(max_sum, u->val);
        }
        
        return max_sum;
    }

private:
    // 修改后的递归函数：同时收集所有节点
    void getNodesAndParents(unordered_map<TreeNode*, TreeNode*>& parent,
                            unordered_map<TreeNode*, int>& prefixSum,
                            vector<TreeNode*>& nodes,
                            TreeNode* node) {
        if (node->left) {
            parent[node->left] = node;
            prefixSum[node->left] = prefixSum[node] + node->left->val;
            nodes.push_back(node->left);
            getNodesAndParents(parent, prefixSum, nodes, node->left);
        }
        if (node->right) {
            parent[node->right] = node;
            prefixSum[node->right] = prefixSum[node] + node->right->val;
            nodes.push_back(node->right);
            getNodesAndParents(parent, prefixSum, nodes, node->right);
        }
    }

    // LCA查找实现（暴力版）
    TreeNode* findLCA(TreeNode* p, TreeNode* q, unordered_map<TreeNode*, TreeNode*>& parent) {
        unordered_set<TreeNode*> ancestors;
        
        // 收集p的所有祖先
        while (p) {
            ancestors.insert(p);
            p = parent[p];
        }
        
        // 查找q的祖先中第一个存在于p祖先集合的节点
        while (q) {
            if (ancestors.count(q)) return q;
            q = parent[q];
        }
        
        return nullptr; // 实际不会发生
    }
};