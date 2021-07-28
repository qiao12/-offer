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
    vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		int left = 0;
		int right = array.size() - 1;
		vector<int> result;
		while (left < right)
		{
			if (array[left] + array[right] == sum)
			{
				result.push_back(array[left]);
				result.push_back(array[right]);
				return result;
			}
			if (array[left] + array[right] > sum)
			{
				right--;
			}
			if (array[left] + array[right] < sum)
			{
				left++;
			}
		}
		return result;
    }
};