#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int main()
{



	system("pause");
	return EXIT_SUCCESS;
}

class Solution {
public:
    int jumpFloorII(int number) {
		if (number == 0 || number == 1)
		{
			return 1;
		}
		if (number == 2 )
		{
			return 2;
		}
		return 2 * jumpFloorII(number - 1);
    }
};