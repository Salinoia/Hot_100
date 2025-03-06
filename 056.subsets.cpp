#include <vector>
using std::vector;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        res.clear();
        path.clear();
        backtracking(nums, 0);
        return res;
    }
private:
    vector<int> path;
    vector<vector<int>> res;
    void backtracking(vector<int>& nums, int start_index){
        res.emplace_back(path);
        if(start_index >= nums.size()) return;
        for(int i = start_index; i < nums.size(); ++i){
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
        return;
    }
};