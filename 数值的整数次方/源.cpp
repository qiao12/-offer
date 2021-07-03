#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    Solution a;
    a.Power(2.0, 3);


	system("pause");
	return EXIT_SUCCESS;
}

class Solution {
public:
    double Power(double base, int exponent) {
        vector<double> dp(exponent, 0);
        if (exponent == 0) {
            return 1.0;
        }
        if (exponent > 0) {
            return Dfs(base, exponent, dp);
        }
        else {
            return 1 / Dfs(base, exponent, dp);
        }
    }
    double Dfs(double base, int exponent, vector<double>& dp) {
        if (exponent == 0) {
            return 1.000;
        }
        if (base == 0) {
            return 0;
        }
        if (dp[exponent] != 0) {
            return dp[exponent];
        }
        if (exponent == 1) {
            return base;
        }
        dp[exponent] = Dfs(base, exponent / 2, dp) * Dfs(base, exponent / 2, dp) * Dfs(base, exponent % 2, dp);
        cout << dp[exponent] << endl;
        return dp[exponent];
    }
};