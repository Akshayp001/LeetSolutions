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
    int len(ListNode* head) {
        int size = 0;
        ListNode* curr = head;
        while (curr != NULL) {
            size++;
            curr = curr->next;
        }
        return size;
    }

     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s;
        int n = len(l1);
        int m = len(l2);
        while(m || n){
            if(m==n){
                s.push(l1->val+l2->val);
                l1=l1->next; l2=l2->next;
                m--;n--;
            }
            else if(m>n){
                s.push(l2->val);
                l2=l2->next; m--;
            }else{
                s.push(l1->val);
                l1=l1->next; n--;
            }
        }
        ListNode* tmp = nullptr;
        int car=0;
        while(!s.empty() || car){
            if(!s.empty()) car+=s.top(),s.pop();
            ListNode* te = new ListNode(car%10);
            te->next = tmp;
            tmp=te;
            car = car/10;        
        }
        return tmp;
    }
};