
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution1 {
public:
    // 计算以当前节点为起点的路径数目
    int countPaths(TreeNode* node, long target) {
        if (!node) return 0;
        
        int count = 0;
        if (node->val == target) count++; // 当前节点本身是否满足
        
        // 递归计算左子树和右子树
        count += countPaths(node->left, target - node->val);
        count += countPaths(node->right, target - node->val);
        
        return count;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;

        int count = countPaths(root, targetSum);

        count += pathSum(root->left, targetSum);
        count += pathSum(root->right, targetSum);
        return count;
    }
};

#include <unordered_map>
class Solution2 {
public:
    int pathSum(TreeNode* root, int targetSum){
        std::unordered_map<long, int> prefixMap;
        prefixMap[0] = 1;// 维护为空路径
        return dfs(root, 0, targetSum, prefixMap);
    }
private:
    int dfs(TreeNode* node, long currentSum, int targetSum, std::unordered_map<long, int>& prefixMap){
        if(!node) return 0;

        currentSum += node->val;
        int result = 0;

        // 如果存在相减后匹配的前缀和，说明存在路径，返回值加一
        if(prefixMap.count(currentSum - targetSum)){
            result += prefixMap[currentSum - targetSum];
        }

        // 记录当前前缀和
        prefixMap[currentSum]++;

        result += dfs(node->left, currentSum, targetSum, prefixMap);
        result += dfs(node->right, currentSum, targetSum, prefixMap);

        // 回溯时移除当前前缀和
        // 为什么说此时存在回溯，因为递归栈的特性就注定了回溯性质
        prefixMap[currentSum]--;

        return result;
    }
};