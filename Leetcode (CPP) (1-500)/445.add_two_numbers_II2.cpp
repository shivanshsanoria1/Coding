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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev=NULL, *curr=head, *temp=NULL;
        while(curr!=NULL)
        {
            temp= curr->next;
            curr->next= prev;
            prev= curr;
            curr= temp;
        }
        return prev;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) { /* numbers in LL1 and LL2 are given in MSB to LSB */
        l1= reverseList(l1); //reverse LL1
        l2= reverseList(l2); //reverse LL2
        ListNode *curr1=l1, *curr2=l2;
        ListNode *dummy = new ListNode(-1); //this is the first node of the final LL
        ListNode *curr= dummy;
        int sum, carry=0;
        while(curr1!=NULL && curr2!=NULL)
        {
            sum = curr1->val + curr2->val + carry;
            carry= sum/10;
            sum= sum%10;
            curr->next = new ListNode(sum);
            curr= curr->next;
            curr1= curr1->next;
            curr2= curr2->next;
        }
        while(curr1!=NULL) //LL1 has more elements remaining
        {
            sum = curr1->val + carry;
            carry= sum/10;
            sum= sum%10;
            curr->next = new ListNode(sum);
            curr= curr->next;
            curr1= curr1->next;
        }
        while(curr2!=NULL) //LL2 has more elements remaining
        {
            sum = curr2->val + carry;
            carry= sum/10;
            sum= sum%10;
            curr->next = new ListNode(sum);
            curr= curr->next;
            curr2= curr2->next;
        }
        if(carry == 1) //final carry is generated from MSB
        {
            curr->next = new ListNode(1);
            curr= curr->next;
        }
        return reverseList(dummy->next);
    }
};