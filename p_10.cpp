#include<unordered_set>
#include<vector>
using namespace std;

class Solution {
public:

	bool isMatch(string s, string p) {
		// preprocessing
		unordered_set<int> es_loc;
		vector<char> c_p;
		int n = 0;
		for (int i = 0; i < p.size(); ++i) {
			if (i + 1 < p.size() and p[i + 1] == '*') {
				es_loc.insert(n);
				c_p.push_back(p[i]);
				++i;
			}
			else c_p.push_back(p[i]);
			++n;
		}

		int m = s.size();
		// dp matrix
		vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));
		dp[0][0] = true; // initialize dp matrix;
		// state transition
		for (int i = 0; i < m + 1; ++i) {
			for (int j = 1; j < n + 1; ++j) {
				unordered_set<int>::iterator p_es = es_loc.find(j - 1);
				// if * character
				if (p_es != es_loc.end()) {
					dp[i][j] = dp[i][j - 1];
					if (i == 0) continue;
					if (match(s[i - 1], c_p[j - 1])) dp[i][j] = dp[i][j] || dp[i - 1][j];
				}
				// actual character
				else {
					if (i == 0) {
						dp[i][j] = false;
						continue;
					}
					if (match(s[i - 1], c_p[j - 1])) dp[i][j] = dp[i - 1][j - 1];
				}
			}
		}
		return dp[m][n];
	}
	bool match(char a, char b) {
		if (b == '.') return true;
		return a == b;
	}
};