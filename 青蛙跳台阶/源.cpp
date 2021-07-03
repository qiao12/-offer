#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

int main()
{

	cout << "hello world" << endl;

	system("pause");
	return EXIT_SUCCESS;
}


class Solution {
public:
	int jumpFloor(int number) {
		vector<int> arr(number + 1);
		arr[0] = 1;
		arr[1] = 1;
		for (int i = 2; i <= number; i++)
		{
			arr[i] = arr[i - 1] + arr[i - 2];
		}
		return arr[number];
	}
};