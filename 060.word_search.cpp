#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                if(dfs(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
private:
    int rows, cols;
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int k){
        if(i >= rows || i < 0 || j >= cols || j < 0 || board[i][j] != word[k]) return false;
        if(k == word.size() - 1) return true;
        board[i][j] = '\0';
        bool res = dfs(board, word, i + 1, j, k + 1)     // 向右
                   || dfs(board, word, i, j + 1, k + 1)  // 向下
                   || dfs(board, word, i - 1, j, k + 1)  // 向左
                   || dfs(board, word, i, j - 1, k + 1); // 向上
        board[i][j] = word[k];
        return res;
    }
};

#include <iostream>
int main(){
    int rows, cols;
    cout << "请输入矩阵行列（大于零的正整数）" << std::endl;
    cin >> rows >> cols;
    Solution s;
    vector<vector<char>> board(rows, vector<char>(cols, '\0'));
    cout << "请按照行主序输入字母表， 以空格或者回车隔开" << std::endl;
    for(vector<char>& row : board){
        for(char& ele : row){
            cin >> ele;
        }
    }
    cout << "请输入测试单词" << std::endl;
    string word;
    cin >> word;
    if(s.exist(board, word)){
        cout << "存在测试单词 " << word << std::endl; 
    }
    else cout << "不存在测试单词"  << word << std::endl;
    return 0;
}