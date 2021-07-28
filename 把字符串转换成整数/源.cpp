#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

int main()
{



	system("pause");
	return EXIT_SUCCESS;
}
class Solution {
public:
    int StrToInt(string str) {
		if (!str.size())
		{
			return 0;
		}
		int result = 0;
		for (int i = 0; i < str.size(); i++)
		{
			if (i == 0 &&(str[0] == '+' || str[0] == '-'))
			{
				continue;
			}
			if (str[i] > '9' || str[i] < '0')
			{
				return 0;
			}
			result = result * 10 + str[i] - '0';
		}
		if (str[0] == '-') result *= (-1);
		return result;
    }
};