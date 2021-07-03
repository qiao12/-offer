#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
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
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
		ListNode* new_head = new ListNode(-1);
		ListNode* cur = new_head;
		ListNode* p1 = pHead1;
		ListNode* p2 = pHead2;
		while (p1 && p2)
		{
			if (p1->val <= p2->val)
			{
				cur->next = p1;
				p1 = p1->next;

			}
			else
			{
				cur->next = p2;
				p2 = p2->next;
			}
			cur = cur->next;
		}
		cur->next = p1 ? p1 : p2;
		return new_head->next;
	}
};

/*

class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		ListNode *vhead = new ListNode(-1);
		ListNode *cur = vhead;
		while (pHead1 && pHead2) {
			if (pHead1->val <= pHead2->val) {
				cur->next = pHead1;
				pHead1 = pHead1->next;
			}
			else {
				cur->next = pHead2;
				pHead2 = pHead2->next;
			}
			cur = cur->next;
		}
		cur->next = pHead1 ? pHead1 : pHead2;
		return vhead->next;
	}
};

*/