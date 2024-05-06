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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;
        while(head!=nullptr){
            if(st.empty()){
                st.push(head);
            }else{
                while(!st.empty() &&(st.top()->val)<(head->val)){
                    st.pop();
                }
                st.push(head);
            }
            head=head->next;
        }
        ListNode* dummy = new ListNode(0,nullptr);
        while(!st.empty()){
            auto t = st.top();st.pop();
            t->next = dummy->next;
            dummy->next = t;
        }
        return dummy->next;

    }
};