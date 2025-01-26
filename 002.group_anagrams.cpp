#include <vector>
#include <string>
#include <numeric>
#include <array>
#include <unordered_map>

using std::string;
using std::vector;

// Solution1: 自定义哈希函数，返回一个size_t类型的值，一般考虑
class Solution {
public:
    // 定义哈希函数，基于字符频率数组计算哈希值
    static size_t hashArray(const std::array<int, 26>& arr) {
        std::hash<int> fn;
        return std::accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, int num) {
            return (acc << 1) ^ fn(num);  // 左移并异或以混合哈希值
        });
    }


    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        auto hash_array = [fn = std::hash<int>{}](const std::array<int, 26>& arr)->size_t{
            return std::accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, int num){
                return (acc << 1) ^ fn(num);
            });
        };

        // 定义哈希表，使用字符频率数组作为键
        // using HashMap = std::unordered_map<std::array<int, 26>, vector<std::string>, decltype(&hashArray)>;
        using HashMap = std::unordered_map<std::array<int, 26>, vector<std::string>, decltype(hash_array)>;
        HashMap u_map(0, hash_array);

        // 遍历字符串数组，构造字符频率数组
        for (string& str : strs) {
            std::array<int, 26> counts{};  // 初始化频率数组
            for (char ch : str) {
                counts[ch - 'a']++;  // 统计每个字符的频率
            }
            u_map[counts].emplace_back(str);  // 将字符串加入对应分组
        }

        // 收集哈希表中的值
        vector<vector<string>> res;
        for (const auto& [key, group] : u_map) {
            res.push_back(group);
        }
        return res;
    }
};
#include<algorithm>
// Solution2: 对每个字符串进行排序比较
class Solution {
public:
    // 主函数：将输入的字符串分组为字母异位词的集合
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 使用 unordered_map 存储键值对，键为排序后的字符串，值为字母异位词组
        std::unordered_map<string, vector<string>> u_map;

        // 遍历输入的字符串数组
        for (string& str : strs) {
            string key = str; // 将当前字符串拷贝一份作为键
            std::sort(key.begin(), key.end()); // 对键进行排序，形成唯一标识
            u_map[key].emplace_back(str); // 将原始字符串加入对应的键的值列表中
        }

        // 将 map 中的值（字母异位词组）转换为结果向量
        vector<vector<string>> res;
        for (auto& [key, value] : u_map) {
            res.push_back(value); // 每组异位词形成一个子向量
        }

        return res; // 返回最终分组结果
    }
};

// 为标准库的模板（如 std::hash）提供用户自定义类型的特化
struct Point {
    int x, y;
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};
namespace std{
    template<>
    struct hash<Point>{
        size_t operator()(const Point& p) const {
            return std::hash<int>{}(p.x) ^ (std::hash<int>{}(p.y) << 1);
        }
    };
}