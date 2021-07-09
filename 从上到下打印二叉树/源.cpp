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

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
	vector<int> PrintFromTopToBottom(TreeNode* root) {
		queue<TreeNode*> que;
		vector<int> result;
		if (!root)
		{
			return result;
		}
		que.push(root);
		while (!que.empty())
		{
			result.push_back(que.front()->val);
			if (que.front() ->left)
			{
				que.push(que.front()->left);
			}
			if (que.front()->right)
			{
				que.push(que.front()->right);
			}
			que.pop();
		}
		return result;

	}
};