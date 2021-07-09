#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

int main()
{



	system("pause");
	return EXIT_SUCCESS;
}

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        unordered_map<int, int> Map;
        for (auto i : numbers) {
            ++Map[i];
        }
        for (auto f : Map) {
            cout << f.first << endl;
            if (f.second > (numbers.size()) / 2) {
                return f.first;
            }
        }
        return 0;
    }
};

/*

������������
˼·

��������� nums �е�����Ԫ�ذ��յ��������򵥵��ݼ���˳��������ô�±�Ϊ n/2��Ԫ�أ��±�� 0 ��ʼ��һ����������

*/
class Solution1 {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};


/*

�������������
˼·

��Ϊ����n/2 �������±걻����ռ���ˣ��������������ѡһ���±��Ӧ��Ԫ�ز���֤���кܴ�ĸ������ҵ�������


*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        while (true) {
            int candidate = nums[rand() % nums.size()];
            int count = 0;
            for (int num : nums)
                if (num == candidate)
                    ++count;
            if (count > nums.size() / 2)
                return candidate;
        }
        return -1;
    }
};


/*

�����ģ�����

*/


class Solution {
    int count_in_range(vector<int>& nums, int target, int lo, int hi) {
        int count = 0;
        for (int i = lo; i <= hi; ++i)
            if (nums[i] == target)
                ++count;
        return count;
    }
    int majority_element_rec(vector<int>& nums, int lo, int hi) {
        if (lo == hi)
            return nums[lo];
        int mid = (lo + hi) / 2;
        int left_majority = majority_element_rec(nums, lo, mid);
        int right_majority = majority_element_rec(nums, mid + 1, hi);
        if (count_in_range(nums, left_majority, lo, hi) > (hi - lo + 1) / 2)
            return left_majority;
        if (count_in_range(nums, right_majority, lo, hi) > (hi - lo + 1) / 2)
            return right_majority;
        return -1;
    }
public:
    int majorityElement(vector<int>& nums) {
        return majority_element_rec(nums, 0, nums.size() - 1);
    }
};
