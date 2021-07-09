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
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param pRoot TreeNode类
     * @return TreeNode类
     */
    TreeNode* swap(TreeNode* pRoot) {
        TreeNode* tmp = pRoot->right;
        pRoot->right = pRoot->left;
        pRoot->left = tmp;
        return pRoot;
    }
    TreeNode* Mirror(TreeNode* pRoot) {
        // write code here
        if (! pRoot)
        {
            return nullptr;
        }
        pRoot->right = Mirror(pRoot->right);
        pRoot->left = Mirror(pRoot->left);
        return swap(pRoot);
    }
/*
    TreeNode* reverse(TreeNode* pRoot) {
        if (!pRoot->left || !pRoot->right)
        {
            return swap(pRoot);
        }
    }
*/

};
