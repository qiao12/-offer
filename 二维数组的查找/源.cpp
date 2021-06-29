/*
��ά�����еĲ���

����
��һ����ά�����У�ÿ��һά����ĳ�����ͬ����ÿһ�ж����մ����ҵ�����˳������

ÿһ�ж����մ��ϵ��µ�����˳�����������һ������������������һ����ά�����һ��������

�ж��������Ƿ��и�������
[
  [1,2,8,9],
  [2,4,9,12],
  [4,7,10,13],
  [6,8,11,15]
]
���� target = 7������ true��

���� target = 3������ false��

*/


#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;


class Solution
{
public:
	Solution(vector<vector<int>>& arr);
	~Solution();
	bool erfen_Find(int target,int i,int right, int left);
	bool digui_Find(int target,int i,int j);

private:
	vector<vector<int>> array;
	bool is_exit;

};

Solution::Solution(vector<vector<int>>& arr)
{
	this->array = arr;
	this->is_exit = false;
}

Solution::~Solution()
{
}
bool Solution::erfen_Find(int target,int i, int right, int left) 
{
	int w = this->array[0].size();
	if (left >= w || right < 0)
	{
		return false;
	}
	int mid = (left+right)/2;
	if (target == array[i][mid])
	{
		return  true;
	}
	if (target > array[i][mid])
	{
		return this->erfen_Find(target, i, right, mid + 1);
	}
	else {
		return this->erfen_Find(target, i, mid - 1, left);
	}




};
bool Solution::digui_Find(int target,int i,int j) {
	if (!target)
	{
		this->is_exit = false;
		return this->is_exit;
	}
	int height = this->array.size();
	int width = this->array[0].size();
	if (i >= height || j >= width)
	{
		return false;
	}
	if (target == this->array[i][j])
	{
		return true;
	}
	if (target < this ->array[i][j])
	{
		return false;
	}
	return digui_Find(target, i + 1, j) || digui_Find(target, i, j + 1);
}

/*

	class Solution {
	public:
		bool Find(int target, vector<vector<int>>& array) {
			int h = array.size();
			int w = array[0].size();

			return  Dfs(target, array, 0, 0, h, w);
		};
		bool Dfs(int target,vector<vector<int>>& array,int i,int j,int h,int w){
			if(i >= h || j >= w){
				return false;
			}
			if(array[i][j] == target)
			{
				return true;
			}
			if(array[i][j] >= target){
				return false;
			}
			return Dfs(target, array, i+1, j, h, w) || Dfs(target, array, i, j+1, h, w);

			}
	};

*/

int main()
{
	system("pause");
	return EXIT_SUCCESS;
}
class Solution1 {
public:
	bool Find(int target, vector<vector<int>>& array) {
		if (!array.size() || !array[0].size()) {
			return false;
		}
		for (int i = 0; i < array.size(); i++) {
			int  left = 0;
			int right = array[i].size() - 1;
			if (Dfs(target, array, i, right, left)) {
				return true;
			}
		}
		return false;

	};
	bool Dfs(int target, vector<vector<int>>& array, int i, int right, int left) {
		int w = array[0].size();
		if (left >= w || right < 0)
		{
			return false;
		}
		int mid = (left + right) / 2;
		if (target == array[i][mid])
		{
			return  true;
		}
		if (target > array[i][mid])
		{
			return Dfs(target, array, i, right, mid + 1);
		}
		else {
			return Dfs(target, array, i, mid - 1, left);
		}
	};
};

 