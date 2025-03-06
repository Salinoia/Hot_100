#include <vector>
using std::vector;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // 暴力思维，对每一个值作为首位，然后对后续的所有位置都进行排列，找到所有的情况以返回
        res.clear();
        path.clear();
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return res;
    }
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int>& nums, vector<bool>& used){
        if(path.size() == nums.size()){
            res.emplace_back(path);
            return;
        }

        for(int i = 0; i < nums.size(); ++i){
            if(used[i] == true) continue;
            used[i] = true;
            path.emplace_back(nums[i]);
            backtracking(nums, used); // 递归
            path.pop_back();// 回溯
            used[i] = false; 
        }
    }
};