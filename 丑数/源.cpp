#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>
using namespace std;

int main()
{

	system("pause");
	return EXIT_SUCCESS;
}
class solution {
public:
	int getuglynumber_solution(int index) {
		int i = 1, j = 1, h = 1;
		vector<int> result(index+1);
		result[1] = 1;
		for (int i = 2; i <= index; i++)
		{
			int num1 = result[i] * 2, num2 = result[j] * 3, num3 = result[h] * 3;
			result[i] = min(num3, min(num2, num1));
			if (result[i] == num1)
			{
				i++;
			}
			else {
				if (result[i] == num2)
				{
					j++;
				}
				else
				{
					h++;
				}
			}
		}
		return result[index];
	}
};

/*

	在计算 dp[i] 时，指针px(x∈{2,3,5}) 的含义是使得 dp[j]* x > dp[i-1] 的最小的下标 j，

*/

class Solution {
public:
    int getuglynumber_solution(int n) {
        vector<int> dp(n + 1);
        dp[1] = 1;
        int p2 = 1, p3 = 1, p5 = 1;
        for (int i = 2; i <= n; i++) {
            int num2 = dp[p2] * 2, num3 = dp[p3] * 3, num5 = dp[p5] * 5;
            dp[i] = min(min(num2, num3), num5);
            if (dp[i] == num2) {
                p2++;
            }
            if (dp[i] == num3) {
                p3++;
            }
            if (dp[i] == num5) {
                p5++;
            }
        }
        return dp[n];
    }
};



//最大堆


class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> factors = { 2, 3, 5 };
        unordered_set<long> seen;
        priority_queue<long, vector<long>, greater<long>> heap;
        seen.insert(1L);
        heap.push(1L);
        int ugly = 0;
        for (int i = 0; i < n; i++) {
            long curr = heap.top();
            heap.pop();
            ugly = (int)curr;
            for (int factor : factors) {
                long next = curr * factor;
                if (!seen.count(next)) {
                    seen.insert(next);
                    heap.push(next);
                }
            }
        }
        return ugly;
    }
};