#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
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
    void swap(vector<int>& array, int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        return;
    }
    vector<int> reOrderArray(vector<int>& array) {
        // write code here
        vector<int> result(array.size());
        int double_tail = 0;
        int single_tail = 1;
        for (int i = 0; i < array.size(); i++)
        {
            if (array[i] & 1)
            {
                result[double_tail + 1] = result[double_tail];
                result[single_tail] = array[i];
                for (int j = double_tail; j > single_tail+1; j++)
                {
                    result[j] = result[j - 1];
                }
                result[single_tail] = array[i];
                double_tail++;  
                single_tail++;

            }
            else
            {
                result[double_tail++] = array[i];
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
    void swap(vector<int>& array, int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        return;
    }
    vector<int> reOrderArray(vector<int>& array) {
        // write code here
        vector<int> result;
        vector<int> tmp1;
        vector<int> tmp2;
        for (int i = 0; i < array.size(); i++)
        {
            if (array[i] & 1)
            {
                tmp1.push_back(array[i]);
            }
            else
            {
                tmp2.push_back(array[i]);
            }
        }
        for (int  i = 0; i < tmp1.size(); i++)
        {
            result.push_back(tmp1[i]);
        }
        for (int  i = 0; i < tmp2.size(); i++)
        {
            result.push_back(tmp2[i]);
        }
        return result;
    }
};

/**/
class Solution {
public:
    /**
       1.冒泡排序，空间复杂度为O(1)
        2.空间复杂度O(n)
        3.相对位置可以改变可以用快速排序
     */
    vector<int> reOrderArray(vector<int>& array) {
        int flag = true;
        while (flag) {
            flag = false;
            for (int i = 1; i < array.size(); ++i) {
                if (array[i - 1] % 2 == 0 && array[i] % 2) {
                    flag = true;
                    swap(array[i - 1], array[i]);
                }
            }
        }
        return array;
    }
    // 多声明一个O(n)空间
    vector<int> reOrderArray(vector<int>& array) {
        vector<int> res;
        for (auto n : array) {
            if (n % 2) {
                res.push_back(n);
            }
        }
        for (auto n : array) {
            if (n % 2 == 0) {
                res.push_back(n);
            }
        }
        return res;
    }

};
/**
   1.冒泡排序，空间复杂度为O(1)
    2.空间复杂度O(n)
    3.相对位置可以改变可以用快速排序
 */

class Solution {
public:

    vector<int> reOrderArray(vector<int>& array) {
        int flag = true;
        while (flag) {
            flag = false;
            for (int i = 1; i < array.size(); ++i) {
                if(array[i-1]%2==0 && array[i]%2){
                    flag = true;
                    swap(array[i-1],array[i]);
                }
            }
        }
        return array;
    }
// 多声明一个O(n)空间
   vector<int> reOrderArray(vector<int>& array) {
        vector<int> res;
        for (auto n: array) {
            if (n % 2) {
                res.push_back(n);
            }
        }
        for (auto n: array) {
            if (n % 2==0) {
                res.push_back(n);
            }
        }
        return res;
    }
 
};