#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int main()
{



	system("pause");
	return EXIT_SUCCESS;
}


class Solution {
    int f(int n, int m) {
        if (n == 1) {
            return 0;
        }
        int x = f(n - 1, m);
        return (m + x) % n;
    }
public:
    int LastRemaining_Solution(int n, int m) {
        return f(n, m);
    }
};
