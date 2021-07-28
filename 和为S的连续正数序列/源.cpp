#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{

	system("pause");
	return EXIT_SUCCESS;
}


/*

回溯时间

输出不符合题意：[[1,2,6],[1,3,5],[1,8],[2,3,4],[2,7],[3,6],[4,5],[9]]

*/
class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum) {
		vector<int> tmp;
		backward(tmp, 1, sum, sum);
		return result;
	}
	void backward(vector<int>& tmp, int n, int sum, int target) {
		if (target == 0)
		{
			result.push_back(tmp);
		}
		for (int i = n; i <= sum; i++)
		{
			tmp.push_back(i);
			backward(tmp, i + 1, sum, target - i);
			tmp.pop_back();
		}
	}
private:
	vector<vector<int>> result;
};

/*

双指针

*/

class Solution {
public:
	vector<vector<int>> findContinuousSequence(int target) {
		vector<vector<int>>vec;
		vector<int> res;
		for (int l = 1, r = 2; l < r;) {
			int sum = (l + r) * (r - l + 1) / 2;
			if (sum == target) {
				res.clear();
				for (int i = l; i <= r; ++i) {
					res.emplace_back(i);
				}
				vec.emplace_back(res);
				l++;
			}
			else if (sum < target) {
				r++;
			}
			else {
				l++;
			}
		}
		return vec;
	}
};



/*

滑动窗口解法

						int left = 0, right = 0;

						while (right < s.size()) {
							window.add(s[right]);
							right++;

							while (valid) {
								window.remove(s[left]);
								left++;
							}
						}

*/
class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum) {
		int left = 1, right = 2;
		int window_sum = 1;
		vector<int> window;
		window.push_back(left);
		vector<vector<int>> result;
		while (right < sum)
		{	
			if (window_sum < sum)
			{
				window_sum += right;
				window.push_back(right);
				right++;
			}
			if (window_sum > sum)
			{
				window.erase(window.begin());
				window_sum -= left;
				left++;
			}
			if (window_sum == sum)
			{
				result.push_back(window);
				window.erase(window.begin());
				window_sum -= left;
				left++;
			}
			
		}
		return result;
	}
};

