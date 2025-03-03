#include <vector>
#include <algorithm>
using std::vector;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 观察规律，易知顺时针旋转90°等价于将矩阵转置再做镜像对称
        // 镜像对称可通过reverse操作实现，转置应该如何模拟呢
        if(matrix.size() == 1) return;
        transpose(matrix);
        for(auto& row : matrix){
            std::reverse(row.begin(), row.end());
        }
        return;
    }


    void transpose(vector<vector<int>>& matrix){
        // 转置作为矩阵运算的基础，实现难度并不高，但此处最大的问题在于，如何实现原地转置？
        int rows = matrix.size();
        int cols = rows; // n * n矩阵

        for(int i = 0; i < rows; ++i){
            for(int j = i; j < cols; ++j){// 注意此处的 j == i
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }
        return;
    }
};