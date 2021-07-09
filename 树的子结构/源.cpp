#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int main()
{



	system("pause");
	return EXIT_SUCCESS;
}

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
		if (!pRoot1 || !pRoot2)
		{
			return false;
		}
		if (pRoot1->val == pRoot2->val && recur(pRoot1->left,pRoot2->left) && recur(pRoot1->right,pRoot2->right)) {
			return true;
		}
		return HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);

	}
	bool recur(TreeNode* pRoot1, TreeNode* pRoot2) {
		if (!pRoot2)
		{
			return true;
		}
		if (!pRoot1) {
			return false;
		}
		if (pRoot1->val != pRoot2->val)
		{
			return false;
		}
		else
		{
			return recur(pRoot1->left, pRoot2->left) && recur(pRoot1->right, pRoot2->right);
		}
	}
};