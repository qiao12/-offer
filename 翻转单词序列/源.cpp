#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<stack>
#include<sstream>
using namespace std;

int main()
{
	system("pause");
	return EXIT_SUCCESS;
}

class Solution {
public:
    string ReverseSentence(string str) {
		stack<string> stk;
		int pre = 0;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == 0x20)
			{
				stk.push(str.substr(pre, i - pre));
				pre = i + 1;

			}
		}
		string result;
		while (!stk.empty())
		{
			result += stk.top();
			result += " ";
			stk.pop();
		}
		return result;
    }
};