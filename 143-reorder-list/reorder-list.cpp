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
    void reorderList(ListNode* head) {
        ListNode* dummy = new ListNode(0,head);
        int n=0;
        ListNode* temp = head;
        while(temp!=nullptr) temp=temp->next,n++;
        stack<ListNode*> s;
        temp =head;
        for(int i=0;i<n;i++){
            if(i>n/2 || (n%2==0 && i==n/2)) s.push(temp);
            temp=temp->next;
        }
        temp = head;
        while(!s.empty()){
            auto t = s.top();s.pop();
            t->next = temp->next;
            temp->next = t;
            temp = temp->next->next;           
        }
        temp->next=nullptr;
        
    }
};