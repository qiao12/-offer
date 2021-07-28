#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{



	system("pause");
	return EXIT_SUCCESS;
}

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int maxs = array[0];//�õ�һ��Ԫ��Ϊ��󣬼�������պô�СΪ1��ֱ�ӷ���

        for (int i = 1; i < array.size(); i++) {   //�ӵڶ���Ԫ�ؿ�ʼ����̬�滮        
            if (array[i - 1] > 0)   array[i] = array[i] + array[i - 1]; //���nums[i-1]>0ʱ�򣬲���nums[i]����С�ڵ���0�����������ĺ�һ������num[i]С��
            maxs = max(maxs, array[i]);
        }

        return maxs;
    }
};


class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int ret = array[0];
        int tmp = 0;
        for (const int k : array) {
            if (tmp + k < 0) {
                tmp = 0;
            }
            else {
                tmp += k;
            }
            ret = max(ret, tmp);
        }
        if (tmp != 0)
            return ret;
        return *max_element(array.begin(), array.end());
    }
};