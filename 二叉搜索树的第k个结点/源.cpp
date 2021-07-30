#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<stack>
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
    TreeNode* KthNode(TreeNode* pRoot, int k) {
        if (k <= 0) {
            return nullptr;
        }
        if (!pRoot) {
            return nullptr;
        }
        vector<TreeNode*> result;
        dfs(pRoot, result);
        return result[k - 1];
    }
    void dfs(TreeNode* root, vector<TreeNode*>& record) {
        if (!root) {
            return;
        }
        dfs(root->left, record);
        record.push_back(root);
        dfs(root->right, record);
    }
};

class Solution {
public:
    int m;
    TreeNode* ans;
    void dfs(TreeNode* p) {
        if (!p || m < 1) return;//不满足条件直接返回NULL/每次递归出口：
        dfs(p->left);//走到了最左边结点,到空不继续递归，该节点左右走完了回溯上一层
        if (m == 1) ans = p;//最左边结点 / m-到1的时候，当前结点就是第m小
        if (--m > 0) dfs(p->right);// 右子树同样处理/遍历该节点的右节点 (左中右)
    }
    TreeNode* KthNode(TreeNode* p, unsigned int k) {
        ans = NULL; m = k;//初始化 ans=NULL 不满足条件返回NULL
        dfs(p);
        return ans;
    }
};
//非递归   死扣递归很多时候还是有必要的，它不仅是一种优美的思路，简洁的代码，更体现的是对函数不断调入与回溯这一过程的整体把握，基于整个递归程序流程的理解再去写非递归会更简单。递归的过程其实就是函数不断的调入，在计算机中每一个函数都是一个栈帧，函数的调入与完成对应入栈与出栈。
//非递归版中序遍历，可以利用栈来模拟递归遍历，首先根入栈，然后令根节点的左孩子不断入栈直到为空，弹出栈顶，令其右孩子入栈，重复以上操作，直到遍历结束或者访问第k个节点为止。
class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, unsigned int k)
    {
        if (!pRoot) return nullptr;
        stack<TreeNode*> res;
        TreeNode* p = pRoot;
        while (!res.empty() || p) {//res是空 and 遍历到空节点
            while (p) {
                res.push(p);
                p = p->left;
            }
            TreeNode* node = res.top();
            res.pop();
            if ((--k) == 0) return node;
            p = node->right;
        }
        return nullptr;
    }
};