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
        ListNode *curr=l1;
        string s1="", s2="", s="";
        while(curr != NULL) //add digits from LL1 into string s1
        {
            s1 += to_string(curr->val);
            curr= curr->next;
        }
        curr=l2;
        while(curr != NULL) //add digits from LL2 into string s2
        {
            s2 += to_string(curr->val);
            curr= curr->next;
        }
        reverse(s1.begin(),s1.end()); //reverse string s1
        reverse(s2.begin(),s2.end()); //reverse string s2
        int n1=s1.length(), n2=s2.length(), i=0, carry=0;
        while(i<n1 && i<n2) //until any one of the strings is finished
        {
            int a=s1[i]-'0', b=s2[i]-'0';
            if(a+b+carry > 9)
            {
                s += to_string(a+b+carry-10);
                carry=1;
            }
            else
            {
                s += to_string(a+b+carry);
                carry=0;
            }
            i++;
        }
        while(i<n1) //if string s1 is left
        {
            int a=s1[i]-'0';
            if(a+carry > 9)
            {
                s += to_string(a+carry-10);
                carry=1;
            }
            else
            {
                s += to_string(a+carry);
                carry=0;
            }
            i++;
        }
        while(i<n2) //if string s2 is left
        {
            int b=s2[i]-'0';
            if(b+carry > 9)
            {
                s += to_string(b+carry-10);
                carry=1;
            }
            else
            {
                s += to_string(b+carry);
                carry=0;
            }
            i++;
        }
        if(carry == 1) //carry is generated from MSB
            s += '1';
        int n=s.length();
        ListNode *ans= new ListNode(s[n-1]-'0'); //add last element of string s
        curr= ans;
        for(int i=n-2; i>=0; i--) //add elements of string s (in reverse order) into ans LL
        {
            curr->next= new ListNode(s[i]-'0');
            curr= curr->next;
        }
        return ans;
    }
};