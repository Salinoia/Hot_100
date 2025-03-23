#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<string>> partition(string s) {
        results.clear();
        path.clear();
        backtracking(s, 0);
        return results;
    }
    void backtracking(const string& s, int index){
        if(index >= s.size()){
            results.emplace_back(path);
        }
        for(int i = index; i < s.size(); ++i){
            // if(isPalindrome(s, index, i)){
            if(PalindromeStatus[index][i]){
                // 获取[index,i]在s中的子串
                path.emplace_back(s.substr(index, i - index + 1));
            }
            else continue;
            backtracking(s, i + 1);
            path.pop_back();
        }
    }
private:
    vector<vector<string>> results;
    vector<string> path;
    vector<vector<bool>> PalindromeStatus;
    bool isPalindrome(const string& s, int startIndex, int endIndex){
        for(int i = startIndex, j = endIndex; i <= j; ++i, --j){
            if(s[i] != s[j]) return false;
        }
        return true;
    }
    void isPalindrome(const string& s){
        PalindromeStatus.resize(s.size(), vector<bool>(s.size(), false));
        // f(i, j) = f(i + 1, j - 1) ^ (s[i] = s[j])
        for(int i = s.size() - 1; i >= 0; --i){
            for(int j = i; j < s.size(); ++j){
                PalindromeStatus[i][j] = (s[i] == s[j]) && PalindromeStatus[i + 1][j - 1];
            }
        }
    }
};