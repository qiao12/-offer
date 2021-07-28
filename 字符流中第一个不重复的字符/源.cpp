#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
	system("pause");
	return EXIT_SUCCESS;
}
class Solution
{
public:
    //Insert one char from stringstream
    void Insert(char ch) {
        if (!map.count(ch) )
        {
            map.insert(pair<char, int>(ch, i));
            i++;
        }
        else
        {
            map[ch] = -1;
        }

    }
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce() {
        char result;
        int p = INT_MAX;
        for (auto i : map) {
            if (i.second != -1)
            {
                if (i.second < p)
                {
                    p = i.second;
                    result = i.first;
                }
            }
        }
        if (p == INT_MAX) { return '#'; }
        return result;
    }

private:
    int i = 0;
    unordered_map<char, int> map;
};