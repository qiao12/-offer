#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main()
{



	system("pause");
	return EXIT_SUCCESS;
}


class Solution {
public:
	int FirstNotRepeatingChar(string str) {
		unordered_map<char, int> map;
		int position = INT_MAX;
		for (size_t i = 0; i < str.size(); i++) {
			if (!map.count(str[i])) {
				map[str[i]] = i;
			}
			else
			{
				map[str[i]] = INT_MAX;
			}
		}
		for (auto i : map)
		{

			position = min(i.second, position);
			//             cout<<position << endl;
			//             cout << i.first << endl;
			//             cout << i.second << endl;
		}
		if (position == INT_MAX) {
			return -1;
		}
		return position;

	}
};