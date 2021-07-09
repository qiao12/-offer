#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	system("pause");
	return EXIT_SUCCESS;
}

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
		if (!sequence.size())
		{
			return false;
		}
		return dfs(sequence, 0, sequence.size()-1);
    }
	bool dfs(vector<int> sequence, int left, int right) {
		if (left >= right)
		{
			return true;
		}
		int i = left;
		while (i < right)
		{
			if (sequence[i] > sequence[right]) { break;}
			i++;
		}
		int j = i;
		while (j < right)
		{
			if (sequence[j] < sequence[right]) { return false; }
			j++;
		}
		return dfs(sequence, left, i - 1) && dfs(sequence, i, right - 1);
	}
};