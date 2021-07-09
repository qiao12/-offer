#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main()
{

	system("pause");
	return EXIT_SUCCESS;
}
class Solution {
public:
	vector<string> Permutation(string str) {
		vector<bool> rec(result.size(), false);
		sort(str.begin(), str.end());
		string S;
		backward(0, str, S, rec);
		return result;
	}
	void backward(int i, string str, string S, vector<bool>& rec) {
		if (i == str.size())
		{
			//cout << S << endl;
			result.push_back(S);
			return;
		}

		for (int j = 0; j < str.size(); j++)
		{
			if (rec[j] || (j > 0 && !rec[j - 1] && str[j - 1] == str[j])) {
				continue;
			}
			rec[j] = true;
			S.push_back(str[j]);
			backward(i + 1, str, S, rec);
			S.pop_back();
			rec[j] = false;
		}
	}
private:
	vector<string> result;

};