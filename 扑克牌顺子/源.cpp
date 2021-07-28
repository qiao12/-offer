#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	system("pause");
	return EXIT_SUCCESS;
}
class Solution {
public:
    bool IsContinuous(vector<int> numbers) {
		sort(numbers.begin(), numbers.end());
		int zero_num = 0;
		for (int i = 0; i < numbers.size(); i++)
		{
			if (numbers[i] == 0)
			{
				zero_num++;
				continue;
			}
			//if (j+1<sz && numbers[j] == numbers[j+1]) return false;
			if (i + 1 < numbers.size() && numbers[i] == numbers[i + 1]) { return false; }

		}
		return  numbers.back() - numbers[zero_num] < 5;
    }
};