#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<memory>

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

//class Solution {
//public:
//    char* Serialize(TreeNode* root) {
//        unique_ptr<string> result (new string);
//        preorder(root, result);
//        cout << *result << endl;
//        return reinterpret_cast<char*>(result.get());
//    }
//    void preorder(TreeNode* root, unique_ptr<string>& result) {
//        if (! root)
//        {
//            *result += "None,";
//        }
//        *result += to_string(root->val) + ',';
//        preorder(root->left,result);
//        preorder(root->right, result);
//    }
//
//    TreeNode* Deserialize(char* str) {
//        string* tmp = reinterpret_cast<string*>(str);
//        vector<string> record;
//        int p = 0;
//        for (size_t i = 0; i < tmp->size(); i++)
//        {
//            if (tmp[i] == ",") {
//                p = i;
//                record.push_back(tmp->substr(p, i - p));
//            }
//        }
//        return decode(record);
//    }
//    TreeNode* decode(vector<string>& str) {
//        if (*str.begin() == "None,")
//        {
//            str.erase(str.begin());
//            return nullptr;
//        }
//        TreeNode* root = new TreeNode(atoi(str.begin()->c_str()));
//        str.erase(str.begin());
//        root->left = decode(str);
//        root->right = decode(str);
//        return root;
//    }
//};

class Solution {
public:
    char* Serialize(TreeNode* root) {
        string* result = new string;
        preorder(root, result);
        cout << *result << endl;
        return const_cast<char*>(result->c_str());
    }
    void preorder(TreeNode* root, string* result) {
        if (!root)
        {
            *result += "#,";
        }
        else
        {
            *result += to_string(root->val) + ',';
            preorder(root->left, result);
            preorder(root->right, result);
        }
    }

    TreeNode* Deserialize(char* str) {
        //         cout << str <<endl;
        string tmp = str;
        vector<string> record;
        if (str[0] == 'n')
        {
            return nullptr;
        }
        int p = -1;
        for (size_t i = 0; i < tmp.size(); i++)
        {
            if (tmp[i] == ',') {
                if (p == -1)
                {
                    cout << tmp.substr(0, i) << endl;
                }
                cout << tmp.substr(p + 1, i - p - 1) << endl;
                record.push_back(tmp.substr(p + 1, i - p - 1));
                p = i;
                //                 record.push_back(tmp.substr(p, i - p));
            }
        }
        return decode(record);
        //         return nullptr;
    }
    TreeNode* decode(vector<string>& str) {
        if (*str.begin() == "#")
        {
            str.erase(str.begin());
            return nullptr;
        }
        TreeNode* root = new TreeNode(atoi(str.begin()->c_str()));
        str.erase(str.begin());
        root->left = decode(str);
        root->right = decode(str);
        return root;
    }
};
class Solution1 {
public:
    char* Serialize(TreeNode* root) {
        shared_ptr<string> result (new string);
        /// <summary>
        /// shared_ptr<string> sp2(new string("Hello"));
        /// </summary>
        /// <param name="root"></param>
        /// <returns></returns>
        preorder(root, result);
        return const_cast<char*>(result.get()->c_str());
    }
    void preorder(TreeNode* root, shared_ptr<string> result) {
        if (!root)
        {
            *result += "#,";
        }
        else
        {
            *result += to_string(root->val) + ',';
            preorder(root->left, result);
            preorder(root->right, result);
        }
    }

    TreeNode* Deserialize(char* str) {
        //         cout << str <<endl;
        string tmp = str;
        vector<string> record;
        if (str[0] == 'n')
        {
            return nullptr;
        }
        int p = -1;
        for (size_t i = 0; i < tmp.size(); i++)
        {
            if (tmp[i] == ',') {
                if (p == -1)
                {
                    cout << tmp.substr(0, i) << endl;
                }
                cout << tmp.substr(p + 1, i - p - 1) << endl;
                record.push_back(tmp.substr(p + 1, i - p - 1));
                p = i;
                //                 record.push_back(tmp.substr(p, i - p));
            }
        }
        return decode(record);
        //         return nullptr;
    }
    TreeNode* decode(vector<string>& str) {
        if (*str.begin() == "#")
        {
            str.erase(str.begin());
            return nullptr;
        }
        TreeNode* root = new TreeNode(atoi(str.begin()->c_str()));
        str.erase(str.begin());
        root->left = decode(str);
        root->right = decode(str);
        return root;
    }
};
class Codec {
public:
    void rserialize(TreeNode* root, string& str) {
        if (root == nullptr) {
            str += "None,";
        }
        else {
            str += to_string(root->val) + ",";
            rserialize(root->left, str);
            rserialize(root->right, str);
        }
    }

    char* serialize(TreeNode* root) {
        string ret;
        rserialize(root, ret);
        return const_cast<char*>(ret.c_str());
    }

    TreeNode* rdeserialize(list<string>& dataArray) {
        if (dataArray.front() == "None") {
            dataArray.erase(dataArray.begin());
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(dataArray.front()));
        dataArray.erase(dataArray.begin());
        root->left = rdeserialize(dataArray);
        root->right = rdeserialize(dataArray);
        return root;
    }

    TreeNode* deserialize(string data) {
        list<string> dataArray;
        string str;
        for (auto& ch : data) {
            if (ch == ',') {
                dataArray.push_back(str);
                str.clear();
            }
            else {
                str.push_back(ch);
            }
        }
        if (!str.empty()) {
            dataArray.push_back(str);
            str.clear();
        }
        return rdeserialize(dataArray);
    }
};
