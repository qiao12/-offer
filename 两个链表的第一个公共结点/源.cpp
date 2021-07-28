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
/*

�����ݹ�

*/
class Solution {
public:
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		if (!pHead1 || !pHead1)
		{
			return nullptr;
		}
		if (pHead1->val == pHead2->val) {
			return pHead1;
		}
		ListNode* result;
		result = FindFirstCommonNode(pHead1, pHead2->next)? FindFirstCommonNode(pHead1, pHead2->next) :(FindFirstCommonNode(pHead1->next, pHead2->next)? FindFirstCommonNode(pHead1->next, pHead2->next): FindFirstCommonNode(pHead1->next, pHead1));
		
		return result;
	}
};
/*

��ϣ����

*/

class Solution {
public:
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		unordered_set<ListNode*> visited;
		ListNode* temp = headA;
		while (temp != nullptr) {
			visited.insert(temp);
			temp = temp->next;
		}
		temp = headB;
		while (temp != nullptr) {
			if (visited.count(temp)) {
				return temp;
			}
			temp = temp->next;
		}
		return nullptr;
	}
};

//���ߣ�LeetCode - Solution
//���ӣ�https ://leetcode-cn.com/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/solution/liang-ge-lian-biao-de-di-yi-ge-gong-gong-pzbs/
//��Դ�����ۣ�LeetCode��
//����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������

class Solution {
public:
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		unordered_set<ListNode*> visit;
		ListNode*  p1 = pHead1;
		while (p1)
		{
			visit.insert(p1);
			p1 = p1->next;
		}
		p1 = pHead2;
		while (p1)
		{
			if (visit.count(p1))
			{
				return p1;
			}
			p1 = p1->next;
		}

		return nullptr;
	}
};

/*

˫ָ�룺

*/
class Solution {
public:
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		if (headA == nullptr || headB == nullptr) {
			return nullptr;
		}
		ListNode* pA = headA, * pB = headB;
		while (pA != pB) {
			pA = pA == nullptr ? headB : pA->next;
			pB = pB == nullptr ? headA : pB->next;
		}
		return pA;
	}
};

class Solution {
public:
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		if (headA == nullptr || headB == nullptr)
			return nullptr;
		//�����A�ĳ���
		ListNode* p1 = headA;
		int len1 = 0;
		while (p1 != nullptr) {
			len1++;
			p1 = p1->next;
		}
		//�����B�ĳ���
		ListNode* p2 = headB;
		int len2 = 0;
		while (p2 != nullptr) {
			len2++;
			p2 = p2->next;
		}
		//�Ƚ����߳��Ȳ�
		int diff = len1 - len2;
		//˵��A��B���������
		if (diff >= 0) {
			p1 = headA;
			//��ΪA��B��diff������A����diff��
			for (int i = 0; i < diff; i++)
				p1 = p1->next;
			p2 = headB;
			//Ȼ��A��Bһ���ߣ�����ʱ˵���ҵ��˵�һ���ཻ�Ľ��
			while (p1 != nullptr) {
				if (p1 == p2)
					return p1;
				p1 = p1->next;
				p2 = p2->next;
			}
		}
		//˵��A��B��
		else {
			p2 = headB;
			//��ΪB��A����diff������B���߸�diff��
			for (int i = 0; i < 0 - diff; i++)
				p2 = p2->next;
			p1 = headA;
			//Ȼ��A��Bһ���ߣ�����ʱ˵���ҵ��˵�һ���ཻ�Ľ��
			while (p2 != nullptr) {
				if (p1 == p2)
					return p1;
				p1 = p1->next;
				p2 = p2->next;
			}
		}
		//ִ�е�����˵��A��B���ཻ������nullptr
		return nullptr;
	}
};
//���ߣ�LeetCode - Solution
//���ӣ�https ://leetcode-cn.com/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/solution/liang-ge-lian-biao-de-di-yi-ge-gong-gong-pzbs/
//��Դ�����ۣ�LeetCode��
//����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������