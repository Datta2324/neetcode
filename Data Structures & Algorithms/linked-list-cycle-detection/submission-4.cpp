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
    bool hasCycle(ListNode* head) {
        ListNode* l = head;
        ListNode* r = head;

        while(r && r->next)
        {
                l = l->next;
                r = r->next->next;

                if(l == r)
                        return true;
        }
        return false;
    }
};
