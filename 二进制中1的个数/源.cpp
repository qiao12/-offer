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
    int  NumberOf1(int n) {
        int result;
        while (n) {
            if (n & 1) {
                ++result;
            }
            n >>= 1;
        }
        return result;

    }
};
/*

方法 二：技巧法

对于上一种解法中，无用操作是，如果当前位是0， 还是会做判断，然后一位一位的移动。

现考虑二进制数：val : 1101000, val - 1 : 1100111 那么val & （val - 1） : 1100000

*/


class Solution1 {
public:
    int  NumberOf1(int n) {
        int result;
        while (n != 0) {
            ++result;
            n = n & n - 1;
            n >>= 1;
        }
        return result;

    }
};
