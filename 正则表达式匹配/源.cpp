#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<unordered_map>
using namespace std;

int main()
{
	system("pause");
	return EXIT_SUCCESS;
}

class Solution {
public:
	bool dp(string s, int i, string p, int j) {
		int n = s.size(), m = p.size();
		if (j == m)
		{
			return i == n;
		}
		if (i == n)
		{
			if ((m - j) % 2 == 1)
			{
				return false;
			}
			for (; j + 1 < m; j += 2)
			{
				if (p[j + 1] != '*')
				{
					return	false;
				}
			}
			return true;
		}

		string key = to_string(i) + ',' + to_string(j);
		if (memo.count(key)) return memo[key];

		bool res = false;
		if (p[j] == '.' || s[i] == p[j]) {
			if (j < m - 1 && p[j + 1] == '*')
			{
				res = dp(s, i, p, j + 2) || dp(s, i + 1, p, j);
			}
			else
			{
				res = dp(s, i + 1, p, j + 1);
			}

		}
		else
		{
			if (j < m - 1 && p[j + 1] == '*')
			{
				res = dp(s, i, p, j + 2);
			}
			else
			{
				res = false;
			}

		}

		memo[key] = res;

		return res;
	}
	bool isMatch(string s, string p) {
		return dp(s, 0, p, 0);
	}
private:
	unordered_map<string, bool> memo;
};



class Solution {
public:
	bool isMatch(string s, string p) {
		int m = s.size();
		int n = p.size();

		auto matches = [&](int i, int j) {
			if (i == 0) {
				return false;
			}
			if (p[j - 1] == '.') {
				return true;
			}
			return s[i - 1] == p[j - 1];
		};

		vector<vector<int>> f(m + 1, vector<int>(n + 1));
		f[0][0] = true;
		for (int i = 0; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (p[j - 1] == '*') {
					f[i][j] |= f[i][j - 2];
					if (matches(i, j - 1)) {
						f[i][j] |= f[i - 1][j];
					}
				}
				else {
					if (matches(i, j)) {
						f[i][j] |= f[i - 1][j - 1];
					}
				}
			}
		}
		return f[m][n];
	}
};