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
    int rectCover(int number) {
		if (number == 0 )
		{
			return number;
		}
		if (number == 1 || number == 2)
		{
			return number;
		}
		return rectCover(number - 1) + rectCover(number - 2);
    }
};