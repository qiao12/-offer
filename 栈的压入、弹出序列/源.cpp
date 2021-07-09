#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main()
{

	system("pause");
	return EXIT_SUCCESS;
}

class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		stack<int> stk;
		int j = 0;
		for (int i = 0; i < pushV.size(); i++)
		{
			stk.push(pushV[i]);
			while (!stk.empty() && j < popV.size() && stk.top() == popV[j])
			{
				stk.pop();
				j++;
			}
		}
		return stk.empty();
	}
};