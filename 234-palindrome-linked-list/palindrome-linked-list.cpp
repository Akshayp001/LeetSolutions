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
    bool isPalindrome(ListNode* head) {
        int n=0;
        if(head->next==nullptr) return true;
        ListNode* ti = new ListNode(0,head);
        while(head!=nullptr) n++,head=head->next;
        head=ti->next;
        stack<int> s;
        cout<<n<<endl;
        for(int i=0;i<n;i++){
            int t =head->val; head=head->next;
            if(n&1 && i==(n/2)) continue;
            if(i<(n/2)) s.push(t);
            else if(s.top()==t) s.pop();
        }
        head=ti->next;
        return s.empty(); 
    }
};