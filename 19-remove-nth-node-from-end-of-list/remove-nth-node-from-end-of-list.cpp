class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(); 
        dummy->next = head;

        ListNode* first = dummy;
        ListNode* second = dummy;
        int temp = n;

        while (temp--) {
            first = first->next;
        }

        while ((first->next) != nullptr) {
            first = first->next;
            second = second->next;
        }

        ListNode* newNode = second->next;
        second->next = newNode->next;
        delete newNode;

        ListNode* newHead = dummy->next;
        delete dummy;

        return newHead;
    }
};
