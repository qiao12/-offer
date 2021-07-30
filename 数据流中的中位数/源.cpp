#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int main()
{
	system("pause");
	return EXIT_SUCCESS;
}
class Solution {
public:
    void Insert(int num) {
        numbers.push_back(num);
        sort(numbers.begin(), numbers.end());
    }

    double GetMedian() {
        int i = numbers.size();
        if (i % 2) {
            return static_cast<double>(numbers[i / 2]);
        }
        else
        {
            return ((static_cast<double>(numbers[i / 2 - 1])) + (static_cast<double>(numbers[i / 2]))) / 2;
        }

    }
private:
    vector<int> numbers;

};
class Solution {
public:
#define SCD static_cast<double>
    vector<int> v;
    void Insert(int num)
    {
        if (v.empty()) {
            v.push_back(num);
        }
        else {
            auto it = lower_bound(v.begin(), v.end(), num);
            v.insert(it, num);
        }
    }

    double GetMedian()
    {
        int sz = v.size();
        if (sz & 1) {
            return SCD(v[sz >> 1]);
        }
        else {
            return SCD(v[sz >> 1] + v[(sz - 1) >> 1]) / 2;
        }
    }

};
class Solution {
public:
#define SCD static_cast<double>
        priority_queue<int> min_q; // 大顶推
        priority_queue<int, vector<int>, greater<int>> max_q; // 小顶堆

        void Insert(int num)
        {

            min_q.push(num); // 试图加入到大顶推

            // 平衡一个两个堆
            max_q.push(min_q.top());
            min_q.pop();

            if (min_q.size() < max_q.size())
                min_q.push(max_q.top());
                max_q.pop();
        }

    

    double GetMedian()
    {
        return min_q.size() > max_q.size() ? SCD(min_q.top()) : SCD(min_q.top() + max_q.top()) / 2;
    }
};