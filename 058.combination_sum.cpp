#include <vector>
#include <algorithm>
using std::vector;

class Solution1 {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // 对候选数组进行排序，以便后续提前终止不必要的递归
        // 虽然题目允许按任意顺序返回结果，但排序有助于剪枝优化
        std::sort(candidates.begin(), candidates.end());

        // 清空结果集和当前组合路径，确保没有残留数据
        result.clear();
        path.clear();

        // 开始回溯搜索，初始 sum 为 0，index 为 0
        backtracking(candidates, 0, target, 0);

        // 返回所有有效组合
        return result;
    }
private:
    // 存储所有有效组合的结果集
    vector<vector<int>> result;

    // 存储当前正在构建的组合路径
    vector<int> path;

    // 回溯函数，用于搜索所有可能的组合
    // candidates: 候选数组
    // sum: 当前组合中已选元素的和
    // target: 目标和
    // index: 当前候选元素的起始索引（避免重复选择之前的元素）
    void backtracking(vector<int>& candidates, int sum, int target, int index) {
        // 如果当前组合的和等于目标值，说明找到一个有效组合
        if (sum == target) {
            result.emplace_back(path); // 将当前组合加入结果集
            return;
        }

        // 遍历候选数组，从当前索引 index 开始，避免重复选择之前的元素
        for (int i = index; i < candidates.size(); ++i) {
            // 如果当前元素加入后会导致 sum 超过 target，则直接终止循环
            // 由于数组已经排序，后续元素也一定会使 sum 超过 target
            if (sum + candidates[i] > target) {
                break;
            }

            // 选择当前元素：将其加入当前组合路径，并更新 sum
            sum += candidates[i];
            path.emplace_back(candidates[i]);

            // 递归调用，继续搜索下一个元素，允许重复选择当前元素（传入 i 而不是 i + 1）
            backtracking(candidates, sum, target, i);

            // 撤销选择：回溯到上一步，移除当前元素并恢复 sum
            path.pop_back();
            sum -= candidates[i];
        }
    }
};


class Solution2 {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end()); // 排序以便提前终止不必要的递归
        result.clear();
        path.clear();
        backtracking(candidates, 0, target, 0);
        return result;
    }
private:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(vector<int>& candidates, int sum, int target, int index) {
        if (sum == target) {
            result.emplace_back(path); // 找到一个有效组合
            return;
        }

        for (int i = index; i < candidates.size(); ++i) {
            if (sum + candidates[i] > target) {
                break; // 由于已经排序，后续的 candidates[i] 都会使 sum 超过 target，可以直接终止
            }

            // 计算当前元素 candidates[i] 最多可以被使用的次数
            int maxCount = (target - sum) / candidates[i];

            // 限制当前元素被使用的次数不超过 maxCount
            for (int count = 1; count <= maxCount; ++count) {
                sum += candidates[i];
                path.emplace_back(candidates[i]);
                backtracking(candidates, sum, target, i + 1); // 注意：这里传入 i + 1 而不是 i，避免重复选择
            }

            // 回溯：撤销选择
            for (int count = 1; count <= maxCount; ++count) {
                path.pop_back();
                sum -= candidates[i];
            }
        }
    }
};
