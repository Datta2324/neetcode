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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        ListNode* one = head;
        ListNode* two = head;
        ListNode* ans = head;

        while(two != NULL && two->next != NULL)
        {
            one = one->next;
            two = two->next->next;
        }

        
        //reverse the second half
        ListNode* prev = nullptr;
        ListNode* cur;
        ListNode* nex;
        cur = one->next;
        one->next = nullptr;
        while(cur!= nullptr)
        {
            nex = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nex;
        }


        ListNode* second = prev;
        ListNode* first = head;
        while(second) {
            ListNode* firstNext = first->next;
            ListNode* secondNext = second->next;

            first->next = second;
            second->next = firstNext;

            first = firstNext;
            second = secondNext;
        }
    }
};
