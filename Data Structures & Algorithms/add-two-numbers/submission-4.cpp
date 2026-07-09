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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;

        int carry = 0;
        int sum;
        ListNode* one = l1;
        ListNode* two = l2;
        ListNode *lastOne, *lastTwo;
        while (one != nullptr && two != nullptr) {
            sum = one->val + two->val + carry;

            int digit = sum % 10;
            carry = sum / 10;

            one->val = digit;
            two->val = digit;
            lastOne = one;
            lastTwo = two;
            one = one->next;
            two = two->next;
        }
        if (one) {
            lastTwo = nullptr;
            while (one) {
                sum = one->val + carry;

                int digit = sum % 10;
                carry = sum / 10;

                one->val = digit;
                lastOne = one;
                one = one->next;
            }
        }
        if (two) {
            lastOne = nullptr;
            while (two) {
                sum = two->val + carry;

                int digit = sum % 10;
                carry = sum / 10;

                two->val = digit;
                lastTwo = two;
                two = two->next;
            }
        }
        if (carry) {
            ListNode* insert = new ListNode(carry);
            if (lastOne)
                lastOne->next = insert;
            else
                lastTwo->next = insert;
        }
        if (lastOne)
            return l1;
        else
            return l2;
    }
};
