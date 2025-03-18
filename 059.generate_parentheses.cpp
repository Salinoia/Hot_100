#include <vector>
#include <string>
using std::vector;
using std::string;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vaildParenthesis.clear();
        combination.clear();
        backtracking(0, 0, n);
        return vaildParenthesis;
    }
private:
    vector<string> vaildParenthesis;
    string combination;
    void backtracking(int openCount, int closeCount, int n){
        if(combination.size() == 2 * n){
            vaildParenthesis.emplace_back(combination);
            return;
        }
        // 如果左括号的使用数量小于最大对数，可以继续添加左括号
        if(openCount < n){
            combination.push_back('(');
            backtracking(openCount + 1, closeCount, n);
            combination.pop_back();
        }
        // 如果右括号的使用数量小于左括号的使用数量，可以继续添加右括号
        if(closeCount < openCount){
            combination.push_back(')');
            backtracking(openCount, closeCount + 1, n);
        }
    }
};