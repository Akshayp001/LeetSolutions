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
    ListNode* doubleIt(ListNode* head) {
        stack<ListNode*> st;
        while(head!=nullptr){
            st.push(head);
            head=head->next;
        }
        int carry=0;
        ListNode* dum = new ListNode(0);
        ListNode* dum2 = new ListNode(0,dum);
        while(!st.empty()){
            auto node = st.top(); st.pop();
            int newVal = node->val *2 + carry;
            carry = newVal/10;
            newVal = newVal%10;
            node->val = newVal;
            node->next =  dum->next;
            dum->next = node;
        }
        if(carry){
            ListNode* node = new ListNode(carry);
            node->next =  dum->next;
            dum->next = node;
        }
        return dum2->next->next;
    }
};