#include <vector>
using std::vector;
class Solution{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        int y0 = 0, y1 = matrix.size() - 1;
        int x0 = 0, x1 = matrix[0].size() - 1;
        vector<int> res;

        while (y0 <= y1 && x0 <= x1) {
            // 上边：左→右
            for (int j = x0; j <= x1; ++j) 
                res.push_back(matrix[y0][j]);
            if (++y0 > y1) break;

            // 右边：上→下
            for (int i = y0; i <= y1; ++i) 
                res.push_back(matrix[i][x1]);
            if (--x1 < x0) break;

            // 下边：右→左
            for (int j = x1; j >= x0; --j) 
                res.push_back(matrix[y1][j]);
            if (--y1 < y0) break;

            // 左边：下→上
            for (int i = y1; i >= y0; --i) 
                res.push_back(matrix[i][x0]);
            ++x0;
        }
        return res;
    }
};
