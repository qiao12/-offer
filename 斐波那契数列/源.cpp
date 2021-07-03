
#include<iostream>
#include<vector>
using namespace std;

int main()
{

	Solution1 a ;
	int result = a.Fibonacci(4);
	cout << result << endl;
	system("pause");
	return EXIT_SUCCESS;
}


/*

方法一：递归

f[n] = f[n-1] + f[n-2]

*/
class Solution {
public:
	int Fibonacci(int n) {
		if (n == 0 || n == 1) {
			return n;
		}
		return Fibonacci(n - 1) + Fibonacci(n - 2);
	}
};


/*

方法二：带备忘录的递归

f[n] = f[n-1] + f[n-2]

*/
class Solution1 {
public:
	int Fibonacci(int n) {
		vector<int> dp(n, -1);

		return Fib(n,dp);
	}
	int Fib(int n, vector<int>& dp) {
		if (n == 0 || n == 1)
		{
			//dp[n] = n;
			return n;
		}
		if (dp[n] != -1) {
			return dp[n];
		}
		dp[n] = Fib(n - 1, dp) + Fib(n - 2, dp);

		return dp[n];

	}

};