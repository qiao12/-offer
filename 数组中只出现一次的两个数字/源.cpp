#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
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
     * @param array int整型vector
     * @return int整型vector
     */
    vector<int> FindNumsAppearOnce(vector<int>& array) {
        // write code here
        vector<int> result;
        sort(array.begin(), array.end());
        for (int  i = 0; i < array.size(); i++)
        {
            if (array[i] ^ array[i+1])
            {
                result.push_back(array[i]);
            }
            else
            {
                i++;
            }
        }
        return result;
        
    }
};  

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param array int整型vector
     * @return int整型vector
     */
    vector<int> FindNumsAppearOnce(vector<int>& array) {
        // write code here
        vector<int> result;
        map<int, int> map;
        for (int i = 0; i < array.size(); i++)
        {
            if (map.count(array[i]))
            {
                map.erase(array[i]);
            }
            else
            {
                map[array[i]] = i;
            }
        }
        for (auto i : map)
        {
            result.push_back(array[i.second]);
        }
        return result;

    }
};