#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<unordered_map>

using namespace std;

int main()
{



	system("pause");
	return EXIT_SUCCESS;
}


struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
        if (!pHead)
        {
            return {};
        }
        RandomListNode* new_head = new RandomListNode(pHead->label);
        unordered_map<RandomListNode*, RandomListNode*> maps{ pair<RandomListNode*,RandomListNode*>{pHead,new_head} };
        RandomListNode* cur = pHead;

        RandomListNode* new_cur = new_head;

        while (cur->next)
        {   
            new_cur->next = new RandomListNode(cur->next->label);
            pair<RandomListNode*, RandomListNode*> listnode{ cur->next,new_cur->next };
            maps.insert(maps.begin(), listnode);
            new_cur = new_cur->next;
            cur = cur->next;
        }
        cur = pHead;
        new_cur = new_head;
        while (cur && new_cur)
        {
            new_cur->random = maps[cur->random];
            new_cur = new_cur->next;
            cur = cur->next;
        }
        return new_head;

    }
};
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        Node* cur = head;
        // 1. 复制各节点，并构建拼接链表
        while (cur != nullptr) {
            Node* tmp = new Node(cur->val);
            tmp->next = cur->next;
            cur->next = tmp;
            cur = tmp->next;
        }
        // 2. 构建各新节点的 random 指向
        cur = head;
        while (cur != nullptr) {
            if (cur->random != nullptr)
                cur->next->random = cur->random->next;
            cur = cur->next->next;
        }
        // 3. 拆分两链表
        cur = head->next;
        Node* pre = head, * res = head->next;
        while (cur->next != nullptr) {
            pre->next = pre->next->next;
            cur->next = cur->next->next;
            pre = pre->next;
            cur = cur->next;
        }
        pre->next = nullptr; // 单独处理原链表尾节点
        return res;      // 返回新链表头节点
    }
};
