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

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot) {
        if (!pRoot) {
            return true;
        }
        return issame(pRoot->left, pRoot->right);
    }
    bool issame(TreeNode* node1, TreeNode* node2)
    {
        if (!node1)
        {
            return node2 == nullptr;
        }
        if (!node2)
        {
            return node1 == nullptr;
        }
        if (node1->val != node2->val) {
            return false;
        }
        return issame(node1->left, node2->right) && issame(node1->right, node2->left);

    }

};