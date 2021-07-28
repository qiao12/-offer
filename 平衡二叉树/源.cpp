#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;
struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};
int main()
{
	system("pause");
	return EXIT_SUCCESS;
}

class Solution {
public:
	bool IsBalanced_Solution(TreeNode* pRoot) {
		TreeDepth(pRoot);

        return judge(pRoot);
	}
	bool judge(TreeNode* root) {
		if (!root) return true;
		return abs(map[root->left] - map[root->right]) <= 1 &&
			judge(root->left) && judge(root->right);
	}
	int TreeDepth(TreeNode* pRoot) {
		return dfs(pRoot);
	}
	int dfs(TreeNode* pRoot) {
		if (!pRoot) { return 0; }
		if (map.find(pRoot) != map.end())
		{
			return map[pRoot];
		}
		map[pRoot] = max(dfs(pRoot->left), dfs(pRoot->right)) + 1;
		return map[pRoot];
	}
private:
	unordered_map<TreeNode*, int> map;
};