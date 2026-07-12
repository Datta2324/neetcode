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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(-1);
        ListNode* newHead = dummy;

        while(true)
        {
            int min = INT_MAX;
            int minNode = -1;
            for(int i = 0; i< lists.size();i++)
            {
                if(lists[i] && (lists[i]->val < min))
                {
                    min = lists[i]->val;
                    minNode = i;
                }
            }
            if(minNode != -1)
            {
                dummy->next = lists[minNode];
                lists[minNode] = lists[minNode]->next;
                dummy = dummy->next;
            }
            // if it didnt enter the loop break as lists might be completed
            // or already sorted
            else
                break;
        }
        return newHead->next; 
        
    }
};
