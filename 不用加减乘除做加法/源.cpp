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
    int Add(int num1, int num2)
    {
        while (num2 != 0) {
            // �������ƻ��ڵ�λ��1������ת��Ϊ�޷�������
            int c = ((unsigned int)(num1 & num2)) << 1;
            num1 ^= num2;
            num2 = c;
        }
        return num1;
    }
};
class Solution {
public:
    int add(int a, int b)
    {
        return (b == 0) ? a : add(a ^ b, (a & b) << 1);
        /*
        if(b == 0)
            return a;
        else
            return add(a ^ b, (a & b) << 1);
            //����� + ������������һλ
        */
    }
};
