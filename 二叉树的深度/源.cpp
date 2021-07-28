#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
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
	int TreeDepth(TreeNode* pRoot) {
		return dfs(pRoot);
	}
	int dfs(TreeNode* pRoot) {
		if (!pRoot) { return 0; }
		return max(dfs(pRoot->left), dfs(pRoot->right)) + 1;
	}
};
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
        if (!pRoot) return 0;
        queue<TreeNode*> q;
        q.push(pRoot);
        int leve1 = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto node = q.front(); q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            leve1 += 1;
        }
        return leve1;
    }
};