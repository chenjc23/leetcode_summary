#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int max_length = 0;
        int left = 0, right = 0;
        // �������
        for (char c : s) {
            if (c == '(') ++left;
            else ++right;
            if (left == right) max_length = max(max_length, left + right);
            else if (right > left) left = right = 0;
        }
        if (left == right) return max_length;

        // �������
        left = right = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == ')') ++right;
            else ++left;
            if (left == right) max_length = max(max_length, left + right);
            else if (right < left) left = right = 0;
        }
        return max_length;
    }
};
