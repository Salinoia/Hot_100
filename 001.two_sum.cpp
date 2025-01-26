#include <vector>
#include <unordered_map>
using std::vector;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 创建一个哈希表，用于存储数组中的值及其对应的索引
        std::unordered_map<int, int> u_map;

        // 遍历数组
        for (int i = 0; i < nums.size(); ++i) {
            // 计算当前数字需要的补数
            int complement = target - nums[i];

            // 在哈希表中查找补数
            auto iter = u_map.find(complement);
            if (iter != u_map.end()) {
                // 如果找到补数，返回补数的索引和当前数字的索引
                return {iter->second, i};
            }

            // 如果补数不存在，将当前数字及其索引存入哈希表
            // nums[i]: 当前数字, i: 当前索引
            u_map.insert(std::pair<int, int>(nums[i], i));
        }

        // 如果没有找到符合条件的两个数字，返回空向量
        return {};
    }
};
