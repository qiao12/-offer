#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
	system("pause");
	return EXIT_SUCCESS;
}
struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead) {
        if (!pHead)
        {
            return pHead;
        }
        unordered_map<int, ListNode*> map;
        ListNode* cur = pHead;
        while (cur)
        {
            if (map.count(cur->val))
            {
                map[cur->val] = nullptr;
            }
            else
            {
                map.insert(pair<int, ListNode*>(cur->val, cur));
            }
            cur = cur->next;
        }
        cur = pHead;
        while (cur) {
            if (map[cur->val]) {
                cout << cur->val << endl;
                break;
            }
            cur = cur->next;
        }
        if (!cur) { return nullptr; }
        ListNode* tmp = new ListNode(cur->val);
        ListNode* p = tmp;
        //         for(auto i : map){
        //             if(i.second){
        //                 cout << i.first << endl;
        //             }
        //         }
        cur = cur->next;
        while (cur)
        {
            if (map[cur->val])
            {
                p->next = new ListNode(cur->val);
                p = p->next;
                //                 cout << cur->val << endl;
            }
            cur = cur->next;
        }
        return tmp;
    }
};