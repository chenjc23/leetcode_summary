#include<vector>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> my_stack;
        my_stack.push(-1); // ��ʼ���ײ�Ԫ��,���һ��δ��ƥ��������ŵ��±�
        int max_length = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(')
                my_stack.push(i);
            else {
                my_stack.pop();
                if (my_stack.empty())
                    my_stack.push(i);
                else
                    max_length = max(max_length, i - my_stack.top());
            }
        }
        return max_length;
    }
};
