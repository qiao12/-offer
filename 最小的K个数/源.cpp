#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<time.h>
using namespace std;

int main()
{



	system("pause");
	return EXIT_SUCCESS;
}

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		vector<int> result;
		if (k > input.size())
		{
			return result;
		}
		sort(input.begin(), input.end());

		for (int i = 0; i < k; i++)
		{
			result.push_back(input[i]);
		}
		return result;
    }
};


/*

����������

˼·���㷨

������һ�������ʵʱά�������ǰ kk Сֵ�����Ƚ�ǰ kk �������������У����ӵ� k+1k+1 ������ʼ������

�����ǰ�����������ȴ���ѵĶѶ�����ҪС���ͰѶѶ������������ٲ��뵱ǰ������������

��󽫴����������������鷵�ؼ��ɡ�������Ĵ����У����� C++ �����еĶѣ������ȶ��У�Ϊ����ѣ�

���ǿ�����ô������ Python �����еĶ�ΪС���ѣ��������Ҫ�����������е���ȡ���෴����

����ʹ��С����ά��ǰ k Сֵ��

*/

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> vec(k, 0);
        if (k == 0) { // �ų� 0 �����
            return vec;
        }
        priority_queue<int> Q;
        for (int i = 0; i < k; ++i) {
            Q.push(arr[i]);
        }
        for (int i = k; i < (int)arr.size(); ++i) {
            if (Q.top() > arr[i]) {
                Q.pop();
                Q.push(arr[i]);
            }
        }
        for (int i = 0; i < k; ++i) {
            vec[i] = Q.top();
            Q.pop();
        }
        return vec;
    }
};



class Solution {
    int partition(vector<int>& nums, int l, int r) {
        int pivot = nums[r];
        int i = l - 1;
        for (int j = l; j <= r - 1; ++j) {
            if (nums[j] <= pivot) {
                i = i + 1;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[r]);
        return i + 1;
    }

    // ��������Ļ���
    int randomized_partition(vector<int>& nums, int l, int r) {
        int i = rand() % (r - l + 1) + l;
        swap(nums[r], nums[i]);
        return partition(nums, l, r);
    }

    void randomized_selected(vector<int>& arr, int l, int r, int k) {
        if (l >= r) {
            return;
        }
        int pos = randomized_partition(arr, l, r);
        int num = pos - l + 1;
        if (k == num) {
            return;
        }
        else if (k < num) {
            randomized_selected(arr, l, pos - 1, k);
        }
        else {
            randomized_selected(arr, pos + 1, r, k - num);
        }
    }

public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        srand((unsigned)time(NULL));
        randomized_selected(arr, 0, (int)arr.size() - 1, k);
        vector<int> vec;
        for (int i = 0; i < k; ++i) {
            vec.push_back(arr[i]);
        }
        return vec;
    }
};
