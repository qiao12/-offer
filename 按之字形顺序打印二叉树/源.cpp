#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
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
    vector<vector<int>> Print(TreeNode* pRoot) {

        vector<vector<int>> result;
        if (!pRoot) { return result; }
        vector<int> tmp;
        stack<TreeNode*> left;
        stack<TreeNode*> right;
        right.push(pRoot);
        while (!left.empty() || !right.empty())
        {
            //             cout << left.top() << endl;
            if (!left.empty()) {
                while (!left.empty()) {
                    if (left.top()->right) right.push(left.top()->right);
                    if (left.top()->left)right.push(left.top()->left);
                    tmp.push_back(left.top()->val);
                    left.pop();
                }
                result.push_back(tmp);
                tmp.clear();
            }
            else {
                while (!right.empty())
                {
                    if (right.top()->left) left.push(right.top()->left);
                    if (right.top()->right) left.push(right.top()->right);
                    tmp.push_back(right.top()->val);
                    right.pop();
                }
                result.push_back(tmp);
                tmp.clear();
            }

        }
        return result;
    }
};