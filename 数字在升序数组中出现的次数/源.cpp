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
    int GetNumberOfK(vector<int> data, int k) {
		if (!data.size())
		{
			return 0;
		}
		int left = 0;
		int right = data.size() - 1;
		int mid;
		while (left < right)
		{
			mid = left + (right - left) / 2;
			if (data[mid] > k)
			{
				right = mid-1;
			}
			if (data[mid] < k)
			{
				left = mid + 1;
			}
			if (data[mid] == k)
			{
				break;
			}
		}
		int result = 0;
		int i = mid, j = mid - 1;
		while (data[i] == k)
		{
			i++;
			result++;
		}
		while (data[j] == k)
		{
			j--;
			result++;
		}
		return result;
    }
};