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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* start = new ListNode();
        ListNode* ans =  new ListNode();

        start->next = ans;

        while(head!=NULL){
            int a=0;
            while(head->val!=0){
                a+=head->val;
                head = head->next;
            }
            ListNode* node = new ListNode(a);
            ans->next = node;
            ans =ans->next;
            head=head->next;
        }

        return start->next->next->next;
                
    }
};