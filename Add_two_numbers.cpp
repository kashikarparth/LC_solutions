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
        int carry = 0;
        int sum = 0;
        
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        
        ListNode* a = new ListNode(0);
        ListNode* temp = a;
        
        while(temp1 and temp2){
            
            sum = (temp1->val + temp2->val + carry);
            carry = sum/10;
            sum%=10;
            
            a->next = new ListNode(sum);
            a =  a->next;
            
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        
        while(temp1){
            sum = (temp1->val + carry);
            carry = sum/10;
            sum%=10;
            
            a->next = new ListNode(sum);
            a = a->next;
            temp1 = temp1->next;
        }
        
        while(temp2){
            sum = (temp2->val + carry);
            carry = sum/10;
            sum%=10;
            
            a->next = new ListNode(sum);
            a = a->next;
            temp2 = temp2->next;
        }
        
        if(carry){
            a->next = new ListNode(carry);
            a = a->next;
        }        
        temp = temp->next;
        return temp;
    }
};