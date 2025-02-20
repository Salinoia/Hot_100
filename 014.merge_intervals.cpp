#include <vector>
#include <algorithm>
using std::vector;
class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if(intervals.size() == 0) res;
        std::sort(intervals.begin(), intervals.end(), cmp);
        res.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); ++i){
            if(intervals[i][0] <= res.back()[1]){ // 元素i左边界小于于元素i-1的右边界
                // 更新元素i-1的右边界
                res.back()[1] = std::max(intervals[i][1], res.back()[1]);
            }
            else {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};