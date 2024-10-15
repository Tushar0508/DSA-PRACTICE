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

    ListNode* partition(ListNode* head, int x) {
        ListNode* temp1=new ListNode();
        ListNode* temp2=new ListNode();

        ListNode* head1=temp1;
        ListNode* head2=temp2;

        while(head){
            if(head->val>=x){
                temp2->next=head;
                head=head->next;
                temp2=temp2->next;
                temp2->next=NULL;
            }
            else{
                temp1->next=head;
                head=head->next;
                temp1=temp1->next;
                temp1->next=NULL;
            }
        }
        temp1->next=head2->next;
        return head1->next;
    }
};