#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
	system("pause");
	return EXIT_SUCCESS;
}
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
        priority_queue<pair<int, int>> p;
        vector<int> ans;
        if (size <= 0)
        {
            return ans;
        }
        if (!num.size())
        {
            return ans;
        }

        int n = num.size();
        if (size > n) {
            return ans;
        }
        for (int i = 0; i < size; ++i)
        {
            p.emplace(num[i], i);
        }

        ans.push_back(p.top().first);
        for (int i = size; i < n; i++)
        {
            p.emplace(num[i], i);
            while (p.top().second <= i - size) {
                p.pop();
            }
            ans.push_back(p.top().first);
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>> q;
        //std::priority_queue<std::string, std::vector<std::string>, std: : greater<std::string>> /
        //    words1{ std::begin(wrds) , std::end(wrds) };
        for (int i = 0; i < k; ++i) {
            q.emplace(nums[i], i);
        }
        vector<int> ans = { q.top().first };
        for (int i = k; i < n; ++i) {
            q.emplace(nums[i], i);
            while (q.top().second <= i - k) {
                q.pop();
            }
            ans.push_back(q.top().first);
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q;
        for (int i = 0; i < k; ++i) {
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
        }

        vector<int> ans = { nums[q.front()] };
        for (int i = k; i < n; ++i) {
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
            while (q.front() <= i - k) {
                q.pop_front();
            }
            ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
        deque<int> p;
        vector<int> ans;
        if (size <= 0)
        {
            return ans;
        }
        if (!num.size())
        {
            return ans;
        }

        int n = num.size();
        if (size > n) {
            return ans;
        }
        for (int i = 0; i < size; ++i) {
            while (!p.empty() && num[i] >= num[p.back()]) {
                p.pop_back();
            }
            p.push_back(i);
        }
        ans.push_back(num[p.front()]);
        for (int i = size; i < n; ++i) {
            while (!p.empty() && p.front() <= i - size) {
                p.pop_front();
            }
            while (!p.empty() && num[i] >= num[p.back()]) {
                p.pop_back();
            }
            p.push_back(i);
            ans.push_back(num[p.front()]);
        }
        return ans;
    }
};