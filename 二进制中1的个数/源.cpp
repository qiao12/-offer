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

���� �������ɷ�

������һ�ֽⷨ�У����ò����ǣ������ǰλ��0�� ���ǻ����жϣ�Ȼ��һλһλ���ƶ���

�ֿ��Ƕ���������val : 1101000, val - 1 : 1100111 ��ôval & ��val - 1�� : 1100000

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
