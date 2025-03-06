#include <vector>
#include <string>

using std::vector;
using std::string;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        combination.clear();
        result.clear();
        if(!digits.size()){
            return result;
        }
        backtracking(digits, 0);
        return result;
    }
private:
    string combination;
    vector<string> result;
    const string letterMap[12] = {
        "", // 0
        "", //1
        "abc", //2
        "def", //3
        "ghi", //4
        "jkl", //5
        "mno", //6
        "pqrs", //7
        "tuv", //8
        "wxyz", //9
        "", // *
        "", // #
    };
    void backtracking(string digits, int index){

        if(digits.size() == combination.size()){
            result.emplace_back(combination);
            return;
        }
        int digit = digits[index] - '0';// 将index指向的数字转为int
        string letters = letterMap[digit];
        for(int i = 0; i < letters.size(); ++i){// 取数字对应的字符集
            
            combination.push_back(letters[i]);// 处理
            
            backtracking(digits, index + 1);// 递归，注意index+1，一下层要处理下一个数字了
            
            combination.pop_back();// 回溯
        }
    }

};