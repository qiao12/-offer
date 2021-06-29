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
    int minNumberInRotateArray(vector<int> rotateArray) {
        int result = INT_MAX;
        for (int i = 0; i < rotateArray.size(); i++) {
            if (result > rotateArray[i]) {
                result = rotateArray[i];
            }
        }
        return result;
    }
};