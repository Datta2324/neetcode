/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverse(ListNode*& cur, int k)
    {
        ListNode* tail = cur;
        ListNode* prev = nullptr;
        ListNode* next;
        int i = 0;
        while(cur && ( i < k) )
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
            i++;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* pos = head;
        int len = 0;
        while(pos)
        {
            pos = pos->next;
            len++;
        }
        pos = head;
        int i = 0;
        ListNode* prevTail = new ListNode(-1);
        ListNode* newHead = nullptr;
        ListNode* returnVal;
        while(pos &&  ((i + k) <= len))
        {
            ListNode* curHead = pos;
            returnVal = reverse(pos,k);
            if(!newHead)
                newHead = returnVal;
            prevTail->next = returnVal;
            prevTail = curHead;
            curHead->next = pos;
            i+=k;
        }
        return newHead;
        
    }
};
