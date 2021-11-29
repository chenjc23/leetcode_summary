#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string cur;
        vector<string> result;
        recursive_generate(cur, result, n, 0, 0);
        return result;
    }

    // 自底向上递归（引用传递）
    void recursive_generate(string& cur, vector<string> &result, int n, int left, int right) {
        // 顶层递归终止条件
        if (cur.size() == 2 * n) {
            result.push_back(cur);
            return;
        }
        if (left < n) {
            cur += "(";     // 本层处理
            recursive_generate(cur, result, n, left + 1, right);    // 上一层递归调用
            cur.pop_back();     // 恢复以处理另一分支
        }
        if (right < left) {
            cur += ")";
            recursive_generate(cur, result, n, left, right + 1);
            cur.pop_back();
        }
    }
};
