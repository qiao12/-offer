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
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param numbers int整型vector
     * @return int整型
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


