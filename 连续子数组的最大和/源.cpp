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
        int maxs = array[0];//让第一个元素为最大，加入数组刚好大小为1，直接返回

        for (int i = 1; i < array.size(); i++) {   //从第二个元素开始，动态规划        
            if (array[i - 1] > 0)   array[i] = array[i] + array[i - 1]; //如果nums[i-1]>0时候，不论nums[i]大于小于等于0，他们两个的和一定不比num[i]小，
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