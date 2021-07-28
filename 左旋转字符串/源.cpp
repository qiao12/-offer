#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

int main()
{
	system("pause");
	return EXIT_SUCCESS;
}

/*

ÓÒÐý×ª

*/

class Solution {
public:
    string LeftRotateString(string str, int n) {
		string result;
		for (int i = str.size()-n; i < str.size(); i++)
		{
			result += str[i];
		}
		for (int i = 0; i < str.size()-n; i++)
		{
			result += str[i];
		}
		return result;

    }
};
/*

×óÐý×ª

*/
class Solution {
public:
	string LeftRotateString(string str, int n) {
		string result;
		for (int i = n; i < str.size(); i++)
		{
			result += str[i];
		}
		for (int i = 0; i < n; i++)
		{
			result += str[i];
		}
		return result;

	}
};
