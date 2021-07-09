#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
int main()
{

	system("pause");
	return EXIT_SUCCESS;
}


// Definition for a Node.
class Node {
public:
	int val;
	Node* left;
	Node* right;

	Node() {}

	Node(int _val) {
		val = _val;
		left = NULL;
		right = NULL;
	}

	Node(int _val, Node* _left, Node* _right) {
		val = _val;
		left = _left;
		right = _right;
	}
};

class Solution {
public:
	Node* treeToDoublyList(Node* root) {
		if (root == nullptr) return nullptr;
		dfs(root);
		head->left = pre;
		pre->right = head;
		return head;
	}
private:
	Node* pre, * head;
	void dfs(Node* cur) {
		if (cur == nullptr) return;
		dfs(cur->left);
		if (pre != nullptr) pre->right = cur;
		else head = cur;
		cur->left = pre;
		pre = cur;
		dfs(cur->right);
	}	
};


class Solution {
public:
	TreeNode* Convert(TreeNode* pRootOfTree) {
		if (!pRootOfTree)
		{
			return nullptr;
		}
		dfs(pRootOfTree);
		head->left = pre;
		pre->right = head;
		return head;
	}
	void dfs(TreeNode* proot) {
		if (!proot) return;
		dfs(proot->left);
		if (!pre) head = proot;
		else pre->right = proot;
		proot->left = pre;
		pre = proot;
		dfs(proot->right);
	}
private:
	TreeNode* pre;
	TreeNode* head;
};