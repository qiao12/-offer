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
/*

����һ�������㷨

*/
class Solution {
public:
    int InversePairs(vector<int> data) {
		int result = 0;
		for (size_t i = 0; i < data.size(); i++)
		{
			for (size_t j = i+1; j < data.size(); j++)
			{
				if (data[i] > data[j])
				{
					result++;
				}
			}
		}
		return result;
    }
};
/*

���������鲢����

*/


class Solution {
public:
    int mergeSort(vector<int>& nums, vector<int>& tmp, int l, int r) {
        if (l >= r) {
            return 0;
        }

        int mid = (l + r) / 2;
        int inv_count = mergeSort(nums, tmp, l, mid) + mergeSort(nums, tmp, mid + 1, r);
        int i = l, j = mid + 1, pos = l;
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) {
                tmp[pos] = nums[i];
                ++i;
                inv_count += (j - (mid + 1));
            }
            else {
                tmp[pos] = nums[j];
                ++j;
            }
            ++pos;
        }
        for (int k = i; k <= mid; ++k) {
            tmp[pos++] = nums[k];
            inv_count += (j - (mid + 1));
        }
        for (int k = j; k <= r; ++k) {
            tmp[pos++] = nums[k];
        }
        copy(tmp.begin() + l, tmp.begin() + r + 1, nums.begin() + l);
        return inv_count;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp(n);
        return mergeSort(nums, tmp, 0, n - 1);
    }
};


class Solution {
public:
    int InversePairs(vector<int> data) {
        int n = data.size();
        vector<int> tmp(n);
        return mergesorted(data, tmp, 0, n - 1);
    }
    int mergesorted(vector<int>& data, vector<int>& tmp, int left, int right) {
        if (left >= right)
        {
            return 0;
        }
        int mid = left + (right - left) / 2;
        int result = mergesorted(data, tmp, left, mid) + mergesorted(data, tmp, mid + 1, right);
        int i = left, j = mid + 1,pos = left;
        while (i <= mid && j <= right)
        {
            if (data[i] <= data[j])
            {
                tmp[pos] = data[i];
                result += j - (mid + 1);
                ++i;
            }
            else
            {
                tmp[pos] = data[j];
                ++j;
            }
            ++pos;
        }
        for (int k = i;k <= mid; k++)
        {
            tmp[pos] = data[k];
            result += j - (mid + 1);
            ++pos;
        }
        for (int k = j; k <= right; k++)
        {
            tmp[pos] = data[k];
            ++pos;
        }

        copy(tmp.begin()+left, tmp.begin()+right+1, data.begin()+left);
        return result;
    }
};

/*

����������ɢ����״����

Ԥ��֪ʶ

����״���项��һ�ֿ��Զ�̬ά������ǰ׺�͵����ݽṹ�����Ĺ����ǣ�

������� update(i, v)�� ������iλ�õ�������һ��ֵv������ v=1

�����ѯ query(i)�� ��ѯ���� [1...i] ���������ͣ��� i λ�õ�ǰ׺��

�޸ĺͲ�ѯ��ʱ����۶��� O(log n)������ n Ϊ��Ҫά��ǰ׺�͵����еĳ��ȡ�


*/

class BIT {
private:
    vector<int> tree;
    int n;

public:
    BIT(int _n) : n(_n), tree(_n + 1) {}

    static int lowbit(int x) {
        return x & (-x);
    }

    int query(int x) {
        int ret = 0;
        while (x) {
            ret += tree[x];
            x -= lowbit(x);
        }
        return ret;
    }

    void update(int x) {
        while (x <= n) {
            ++tree[x];
            x += lowbit(x);
        }
    }
};

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp = nums;
        // ��ɢ��
        sort(tmp.begin(), tmp.end());
        for (int& num : nums) {
            /*tmpΪ����������������*/
            num = lower_bound(tmp.begin(), tmp.end(), num) - tmp.begin() + 1;
            //lower_bound() ����������ָ�������ڲ��Ҳ�С��Ŀ��ֵ�ĵ�һ��Ԫ�ء�
        }
        // ��״����ͳ�������
        BIT bit(n);
        int ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            ans += bit.query(nums[i] - 1);
            bit.update(nums[i]);
        }
        return ans;
    }
};


