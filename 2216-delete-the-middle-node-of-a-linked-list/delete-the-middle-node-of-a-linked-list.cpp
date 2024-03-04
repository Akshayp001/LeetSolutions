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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==nullptr) return nullptr;
        ListNode* ptr1= head;
        ListNode* ptr2= new ListNode(0,head);
        while(ptr1->next!=nullptr){
            ptr1 = ptr1->next;
            if(ptr1->next!=nullptr) ptr1=ptr1->next;
            ptr2 = ptr2->next;            
        }
        //delete 
        ListNode* temp = ptr2->next;
        ptr2->next = temp->next;
        delete temp;
        return head;        
    }
};