#include <vector>
#include <cmath>
#include <climits>
using std::vector;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        if(target < matrix[0][0] || target > matrix[m - 1][n - 1]) return false;
        int x = 0, y = n - 1;
        while(x < m && y >= 0){
            if(matrix[x][y] == target){
                return true;
            }
            else if(matrix[x][y] > target){
                y--;
            }
            else x++;
        }
        return false;
    }
};

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    for (const auto& row: matrix) {
        auto it = lower_bound(row.begin(), row.end(), target);
        if (it != row.end() && *it == target) {
            return true;
        }
    }
    return false;
}