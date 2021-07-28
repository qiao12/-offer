#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<unordered_set>
using namespace std;

int main()
{
	system("pause");
	return EXIT_SUCCESS;
}

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {

        ListNode* fast = pHead;

        ListNode* slow = pHead;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) break;
        }
        if (!fast || !fast->next) return nullptr;
        fast = pHead;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};

class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        unordered_set<ListNode*> st;
        while (pHead) {
            if (st.find(pHead) == st.end()) {
                st.insert(pHead);
                pHead = pHead->next;
            }
            else {
                return pHead;
            }
        }
        return nullptr;
    }
};