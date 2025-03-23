#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        // 行列斜边都不能放
        results.clear();
        vector<string> board(n, string(n, '.'));
        dfs(board, n, 0);
        return results;
    }
private:
    vector<vector<string>> results;
    void dfs(vector<string>& board, int n, int row){
        if(row == n){
            results.emplace_back(board);
            return;
        }
        for(int col = 0; col < n; ++col){
            if(isValid(row, col, board, n)){
                board[row][col] = 'Q';
                dfs(board, n, row + 1);
                board[row][col] = '.';
            }
        }
    }
    bool isValid(int row, int col, vector<string>& board, int n){
        // 行可以不必检查，因为回溯逻辑可以保证必然不会出现同行皇后
        // for(int i = 0; i < n; ++i){ // 检查行
        //     if(board[i][col] == 'Q') return false;
        // }
        for(int i = 0; i < n; ++i){ // 检查列
            if(board[row][i] == 'Q') return false;
        }
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j){
            if(board[i][j] == 'Q') return false;
        }
        for(int i = row - 1, j = col + 1; i >=0 && j < n; --i, ++j){
            if(board[i][j] == 'Q') return false;
        }
        return true;
    }
};

#include <iostream>

int main(){
    Solution s;
    int n;
    std::cout << "请输入需要测试的棋盘大小: (大于零的正整数)" << std::endl;
    std::cin >> n;
    vector<vector<string>> boards = s.solveNQueens(n);
    if(boards.empty()){
        std::cout << n << "皇后无解"  << std::endl;
        return 0;
    }
    for(vector<string>& board : boards){
        for(string& row : board){
            std::cout << row << std::endl;
        }
        std::cout << std::endl;
    }
}