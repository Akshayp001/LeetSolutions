/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL||head->next==NULL) return false;
        ListNode* node = new ListNode();
        node->next = head;
        ListNode* ptr1=node->next,*ptr2=node->next;
        while(ptr1!=nullptr && ptr2!=nullptr){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            if(ptr2!=nullptr) ptr2=ptr2->next;
            if(ptr1==ptr2) return true;
        }
        return false;
    }
};