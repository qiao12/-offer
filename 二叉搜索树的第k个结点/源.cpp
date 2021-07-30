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
        if (!p || m < 1) return;//����������ֱ�ӷ���NULL/ÿ�εݹ���ڣ�
        dfs(p->left);//�ߵ�������߽��,���ղ������ݹ飬�ýڵ����������˻�����һ��
        if (m == 1) ans = p;//����߽�� / m-��1��ʱ�򣬵�ǰ�����ǵ�mС
        if (--m > 0) dfs(p->right);// ������ͬ������/�����ýڵ���ҽڵ� (������)
    }
    TreeNode* KthNode(TreeNode* p, unsigned int k) {
        ans = NULL; m = k;//��ʼ�� ans=NULL ��������������NULL
        dfs(p);
        return ans;
    }
};
//�ǵݹ�   ���۵ݹ�ܶ�ʱ�����б�Ҫ�ģ���������һ��������˼·�����Ĵ��룬�����ֵ��ǶԺ������ϵ����������һ���̵�������գ����������ݹ�������̵������ȥд�ǵݹ����򵥡��ݹ�Ĺ�����ʵ���Ǻ������ϵĵ��룬�ڼ������ÿһ����������һ��ջ֡�������ĵ�������ɶ�Ӧ��ջ���ջ��
//�ǵݹ�������������������ջ��ģ��ݹ���������ȸ���ջ��Ȼ������ڵ�����Ӳ�����ջֱ��Ϊ�գ�����ջ���������Һ�����ջ���ظ����ϲ�����ֱ�������������߷��ʵ�k���ڵ�Ϊֹ��
class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, unsigned int k)
    {
        if (!pRoot) return nullptr;
        stack<TreeNode*> res;
        TreeNode* p = pRoot;
        while (!res.empty() || p) {//res�ǿ� and �������սڵ�
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