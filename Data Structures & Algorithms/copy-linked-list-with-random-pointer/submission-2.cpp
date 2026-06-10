/*
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
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if(head == nullptr)
            return nullptr;
        //Interleave original and dups
        Node* temp = head;
        while(temp != nullptr)
        {
            Node* insert = new Node(temp->val);
            insert->next = temp->next;
            temp->next = insert;
            temp = temp->next->next;
        }
        //Adjust Randoms
        temp = head;
        while(temp != nullptr)
        {
            if(temp->random == nullptr)
            {
                 temp->next->random = nullptr;
                 temp = temp->next->next;
            }
            else
            {
                temp->next->random = temp->random->next;
                temp = temp->next->next;
            }
        }
        //Adjust nexts
        temp = head;
        Node* dupHead = new Node(head->val);
        Node* pos = dupHead;
        while(temp != nullptr)
        {
            pos->next = temp->next;
            temp->next = temp->next->next;
            pos = pos->next;
            temp = temp->next;
        }

        return dupHead->next;
    }
};
