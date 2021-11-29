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

    // �Ե����ϵݹ飨���ô��ݣ�
    void recursive_generate(string& cur, vector<string> &result, int n, int left, int right) {
        // ����ݹ���ֹ����
        if (cur.size() == 2 * n) {
            result.push_back(cur);
            return;
        }
        if (left < n) {
            cur += "(";     // ���㴦��
            recursive_generate(cur, result, n, left + 1, right);    // ��һ��ݹ����
            cur.pop_back();     // �ָ��Դ�����һ��֧
        }
        if (right < left) {
            cur += ")";
            recursive_generate(cur, result, n, left, right + 1);
            cur.pop_back();
        }
    }
};
