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
    int minNumberInRotateArray(vector<int> rotateArray) {
        int right = rotateArray.size() - 1;
        int left = 0;
        while (left < right) {

            int mid = left + (right - left) / 2;

            if (rotateArray[mid] > rotateArray[right]) {
                left = mid + 1;
            }
            else if (rotateArray[mid] < rotateArray[left]) {
                right = mid;
            }
            else {
                right = right - 1;
            }
        }
        return rotateArray[left];

    }
};

/*

±©Á¦Ëã·¨

*/

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int result = INT_MAX;
        for (int i = 0; i < rotateArray.size(); i++)
        {
            if (rotateArray[i] < result)
            {
                result = rotateArray[i];
            }
        }
        return result;

    }
};
