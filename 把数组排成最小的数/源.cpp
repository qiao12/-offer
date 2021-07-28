#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main()
{

	system("pause");
	return EXIT_SUCCESS;
}
/*
class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> strs;
        for(int i = 0; i < nums.size(); i++)
            strs.push_back(to_string(nums[i]));
        quickSort(strs, 0, strs.size() - 1);
        string res;
        for(string s : strs)
            res.append(s);
        return res;
    }
private:
    void quickSort(vector<string>& strs, int l, int r) {
        if(l >= r) return;
        int i = l, j = r;
        while(i < j) {
            while(strs[j] + strs[l] >= strs[l] + strs[j] && i < j) j--;
            while(strs[i] + strs[l] <= strs[l] + strs[i] && i < j) i++;
            swap(strs[i], strs[j]);
        }
        swap(strs[i], strs[l]);
        quickSort(strs, l, i - 1);
        quickSort(strs, i + 1, r);
    }
};
*/

class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> strs;
        string res;
        for (int i = 0; i < nums.size(); i++)
            strs.push_back(to_string(nums[i]));
        sort(strs.begin(), strs.end(), [](string& x, string& y) { return x + y < y + x; });
        for (int i = 0; i < strs.size(); i++)
            res.append(strs[i]);
        return res;
    }
};


class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        vector<string> strs;
        for (int i = 0; i < numbers.size(); i++)
        {
            strs.push_back(to_string(numbers[i]));
        }
        quickSort(strs, 0, numbers.size()-1);
        string result;
        for (int i = 0; i < strs.size() ; i++)
        {
            result.append(strs[i]);
        }
        return result;
    }
    //void swap(vector<string> str, int i, int j) {
    //    string tmp = str[i];
    //    str[i] = str[j];
    //    str[j] = tmp;
    //    return;
    //}
private:
    void quickSort(vector<string>& strs, int l, int r) {
        if (l >= r) return;
        int i = l, j = r;
        while (i < j) {
            while (strs[j] + strs[l] >= strs[l] + strs[j] && i < j) j--;
            while (strs[i] + strs[l] <= strs[l] + strs[i] && i < j) i++;
            swap(strs[i], strs[j]);
        }
        swap(strs[i], strs[l]);
        quickSort(strs, l, i - 1);
        quickSort(strs, i + 1, r);
    }
};

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        vector<string> strs;
        for (int i = 0; i < numbers.size(); i++)
        {
            strs.push_back(to_string(numbers[i]));
        }
        quickSort(strs, 0, numbers.size() - 1);
        string result;
        for (int i = 0; i < strs.size(); i++)
        {
            result.append(strs[i]);
        }
        return result;
    }
    void swap(vector<string>& str, int i, int j) {
        string tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        return;
    }
private:
    void quickSort(vector<string>& strs, int left, int right) {
        if (left >= right) return;
        int i = left, j = right;
        while (i < j) {
            while (strs[j] + strs[left] >= strs[left] + strs[j] && i < j) j--;
            while (strs[i] + strs[left] <= strs[left] + strs[i] && i < j) i++;
            swap(strs, i, j);
        }
        swap(strs, i, left);
        quickSort(strs, left, i - 1);
        quickSort(strs, i + 1, right);
    }
};