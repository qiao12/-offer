#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int main()
{

	system("pause");
	return EXIT_SUCCESS;
}

class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param numbers int����vector
     * @return int����
     */
    int duplicate(vector<int>& numbers) {
        // write code here
        unordered_set<int> set;
        for (int i = 0; i < numbers.size(); i++)
        {
            if (!set.count(numbers[i]))
            {
                set.insert(numbers[i]);
            }
            else
            {
                return numbers[i];
            }
        }
        return -1;
    }
};


