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
    int getDecimalValue(ListNode* head) {
        int ans=0;
        ListNode* t = new ListNode();
        t->next = head;
        while(head!=nullptr){
            ans<<=1; // or ans*=2;
            ans+=head->val;
            head=head->next;
        }
        head=t->next;
        return ans;        
    }
};