
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stack>
using namespace std;

int main()
{



    system("pause");
    return EXIT_SUCCESS;
}
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param pHead ListNode��
     * @param k int����
     * @return ListNode��
     */
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        if (!k) {
            return NULL;
        }
        if (!pHead) {
            return NULL;
        }
        ListNode* fast = pHead;
        ListNode* slow = pHead;
        for (int i = 0; i < k; i++)
        {
            if (!fast) {
                return NULL;
            }
            fast = fast->next;
        }
        while (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};
class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param pHead ListNode��
     * @param k int����
     * @return ListNode��
     */
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        if (!pHead || !k) { return nullptr;}
        stack<ListNode*> stack;
        ListNode* P1 = pHead;
        while (P1)
        {
            stack.push(P1);
            P1 = P1->next;
        }
        ListNode* result;
        while (k && !stack.empty())
        {
            result = stack.top();
            stack.pop();
            k--;
        }
        return result;
    }
    pair<ListNode*, ListNode*> myReverse(ListNode* head, ListNode* tail) {
        ListNode* prev = tail->next;
        ListNode* p = head;
        while (prev != tail) {
            ListNode* nex = p->next;
            p->next = prev;
            prev = p;
            p = nex;
        }
        return { tail, head };
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* hair = new ListNode(0);
        hair->next = head;
        ListNode* pre = hair;

        while (head) {
            ListNode* tail = pre;
            // �鿴ʣ�ಿ�ֳ����Ƿ���ڵ��� k
            for (int i = 0; i < k; ++i) {
                tail = tail->next;
                if (!tail) {
                    return hair->next;
                }
            }
            ListNode* nex = tail->next;
            // ������ C++17 ��д����Ҳ����д��
            // pair<ListNode*, ListNode*> result = myReverse(head, tail);
            // head = result.first;
            // tail = result.second;
            pair<ListNode*, ListNode*> result = myReverse(head, tail);
            head = result.first;
            tail = result.second;
            // �����������½ӻ�ԭ����
            pre->next = head;
            tail->next = nex;
            pre = tail;
            head = tail->next;
        }

        return hair->next;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* new_head;

        if (!head->next) {
            new_head = head;
            new_head->next = nullptr;
            return new_head;
        }
        new_head = rotateRight(head->next, k);
        ListNode* cur = new_head;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = head;
        cur->next->next = nullptr;
        return new_head;
    }
};