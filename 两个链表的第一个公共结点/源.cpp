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

暴力递归

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

哈希集合

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

//作者：LeetCode - Solution
//链接：https ://leetcode-cn.com/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/solution/liang-ge-lian-biao-de-di-yi-ge-gong-gong-pzbs/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

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

双指针：

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
		//计算出A的长度
		ListNode* p1 = headA;
		int len1 = 0;
		while (p1 != nullptr) {
			len1++;
			p1 = p1->next;
		}
		//计算出B的长度
		ListNode* p2 = headB;
		int len2 = 0;
		while (p2 != nullptr) {
			len2++;
			p2 = p2->next;
		}
		//比较两者长度差
		int diff = len1 - len2;
		//说明A比B长或者相等
		if (diff >= 0) {
			p1 = headA;
			//因为A比B长diff，所以A先走diff步
			for (int i = 0; i < diff; i++)
				p1 = p1->next;
			p2 = headB;
			//然后A，B一起走，相遇时说明找到了第一个相交的结点
			while (p1 != nullptr) {
				if (p1 == p2)
					return p1;
				p1 = p1->next;
				p2 = p2->next;
			}
		}
		//说明A比B短
		else {
			p2 = headB;
			//因为B比A长负diff，所以B先走负diff步
			for (int i = 0; i < 0 - diff; i++)
				p2 = p2->next;
			p1 = headA;
			//然后A，B一起走，相遇时说明找到了第一个相交的结点
			while (p2 != nullptr) {
				if (p1 == p2)
					return p1;
				p1 = p1->next;
				p2 = p2->next;
			}
		}
		//执行到这里说明A，B不相交，返回nullptr
		return nullptr;
	}
};
//作者：LeetCode - Solution
//链接：https ://leetcode-cn.com/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/solution/liang-ge-lian-biao-de-di-yi-ge-gong-gong-pzbs/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。