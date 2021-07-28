#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	system("pause");
	return EXIT_SUCCESS;
}


struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

    }
};
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        if (!pNode)
        {
            return nullptr;
        }
        TreeLinkNode* root = nullptr;
        TreeLinkNode* tmp = pNode;
        while (tmp)
        {
            root = tmp;
            tmp = tmp->next;
        }

        dfs(root, pNode->val);
        for (int i = 0; i < record.size(); i++)
        {
            if (record[i]->val == pNode->val) {
                if (i + 1 < record.size())
                {
                    return record[i + 1];
                }
            }
        }
        return nullptr;
    }
    void dfs(TreeLinkNode* node,int val) {
        if (!node)
        {
            return;
        }
        //if (node->val == val)
        //{
        //    return node;
        //}
        dfs(node->left, val);

        record.push_back(node);
        dfs(node->right, val);
        
    }

private:
    vector<TreeLinkNode*> record;
};


class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if (!pNode) {
            return pNode;
        }

        // 属于[2 3 6]类
        if (pNode->right) {
            pNode = pNode->right;
            while (pNode->left) {
                pNode = pNode->left;
            }
            return pNode;
        }

        // 属于 [1] 和 [4 5]
        while (pNode->next) {
            TreeLinkNode* root = pNode->next;
            if (root->left == pNode) {
                return root;
            }
            pNode = pNode->next;
        }

        // 属于[7]
        return nullptr;
    }
};