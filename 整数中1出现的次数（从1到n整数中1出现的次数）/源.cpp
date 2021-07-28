#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	system("pause");
	return EXIT_SUCCESS;
}


/*

class Solution:
    def countDigitOne(self, n: int) -> int:
        digit, res = 1, 0
        high, cur, low = n // 10, n % 10, 0
        while high != 0 or cur != 0:
            if cur == 0: res += high * digit
            elif cur == 1: res += high * digit + low + 1
            else: res += (high + 1) * digit
            low += cur * digit
            cur = high % 10
            high //= 10
            digit *= 10
        return res
*/
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n) {
        int digit = 1;
        int res = 0;
        int high= n / 10, cur = n % 10,low = 0;
        while (high != 0 || cur != 0)
        {
            if (cur == 1) res += high * digit + low + 1;
            else
            {
                if (cur == 0) res += high * digit;
                else { res += (high + 1) * digit; }
            }
            low += cur * digit;
            cur = high % 10;    
            high /= 10;
            digit *= 10;
        }
        return res;
    }
};