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
	vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int> result;
		int top = 0;
		int bottom = matrix.size()-1;
		int left = 0;
		int right = matrix[0].size() - 1;
		while (top <= bottom && left <=right)
		{
			for (int i = left; i <= right; i++) {
				result.push_back(matrix[top][i]);
			}
			for (int i =top+1; i <= bottom; i++)
			{
				result.push_back(matrix[i][right]);
			}

			if (left < right && top < bottom)
			{
				for (int i = right; i > left; i--)
				{
					result.push_back(matrix[bottom][i]);
				}
				for (int i = bottom - 1; i > top; i--)
				{
					result.push_back(matrix[i][left]);
				}
			}

			top++, left++;
			bottom--, right--;
		}
		return result;
	}
	void push_value(vector<vector<int>> matrix,vector<int>& result,int i,int j,int height,int width,)
};