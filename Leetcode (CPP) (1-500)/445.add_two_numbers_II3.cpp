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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1, st2;
        ListNode *curr=l1;
        while(curr!=NULL) //push node values from LL1 into stack1
        {
            st1.push(curr->val);
            curr= curr->next;
        }
        curr=l2;
        while(curr!=NULL) //push node values from LL2 into stack2
        {
            st2.push(curr->val);
            curr= curr->next;
        }
        int sum, carry=0;
        ListNode *head=NULL;
        while(!st1.empty() && !st2.empty()) //both stack1 and stack2 are non empty
        {
            sum = st1.top() + st2.top() + carry;
            st1.pop();
            st2.pop();
            carry= sum/10;
            sum= sum%10;
            ListNode *newNode = new ListNode(sum); //create new node
            newNode->next= head; //connect new node with head 
            head= newNode; //move head in reverse
        }
        while(!st1.empty()) //stack1 is non empty
        {
            sum = st1.top() + carry;
            st1.pop();
            carry= sum/10;
            sum= sum%10;
            ListNode *newNode = new ListNode(sum); //create new node
            newNode->next= head; //connect new node with head 
            head= newNode; //move head in reverse
        }
        while(!st2.empty()) //stack2 is non empty
        {
            sum = st2.top() + carry;
            st2.pop();
            carry= sum/10;
            sum= sum%10;
            ListNode *newNode = new ListNode(sum); //create new node
            newNode->next= head; //connect new node with head 
            head= newNode; //move head in reverse
        }
        if(carry == 1) //carry generated from MSB
        {
            ListNode *newNode = new ListNode(1);
            newNode->next= head;
            head= newNode;
        }
        return head;
    }
};