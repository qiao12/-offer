#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
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
    vector<vector<int>> Print(TreeNode* pRoot) {

        vector<vector<int>> result;
        if (!pRoot) { return result; }
        vector<int> tmp;
        queue<TreeNode*> left;
        queue<TreeNode*> right;
        right.push(pRoot);
        while (!left.empty() || !right.empty())
        {
            //             cout << left.top() << endl;
            if (!left.empty()) {
                while (!left.empty()) {
                    if (left.front()->left) right.push(left.front()->left);
                    if (left.front()->right)right.push(left.front()->right);
                    tmp.push_back(left.front()->val);
                    left.pop();
                }
                result.push_back(tmp);
                tmp.clear();
            }
            else {
                while (!right.empty())
                {
                    if (right.front()->left) left.push(right.front()->left);
                    if (right.front()->right) left.push(right.front()->right);
                    tmp.push_back(right.front()->val);
                    right.pop();
                }
                result.push_back(tmp);
                tmp.clear();
            }

        }
        return result;
    }

};