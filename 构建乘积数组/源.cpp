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
    vector<int> multiply(const vector<int>& A) {
		vector<int> B;
		for (int i = 0; i < A.size(); i++)
		{
			int tmp = 1;
			for (int j = 0; j < A.size(); j++)
			{
				if (i == j)
				{
					continue;
				}
				tmp *= A[j];
			}
			B.push_back(tmp);
		}
		return B;
    }
};


class Solution {
public:
	vector<int> constructArr(vector<int>& a) {
		int len = a.size();
		if (len == 0) return {};
		vector<int> b(len, 1);
		b[0] = 1;
		int tmp = 1;
		for (int i = 1; i < len; i++) {
			b[i] = b[i - 1] * a[i - 1];
		}
		for (int i = len - 2; i >= 0; i--) {
			tmp *= a[i + 1];
			b[i] *= tmp;
		}
		return b;
	}
};
