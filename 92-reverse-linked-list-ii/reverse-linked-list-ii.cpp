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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || !head->next) return head;

        ListNode dummy = ListNode(0, head);
        ListNode* prev = &dummy;
        ListNode* curr;
        ListNode* forw;
        unsigned short pos = 0;

        for (; pos < left-1; pos++) prev = prev->next;

        curr = prev->next;

        for (; pos < right-1; pos++) {
            forw = curr->next;
            curr->next = forw->next;
            forw->next = prev->next;
            prev->next = forw;
        }

        return dummy.next;
    }
};