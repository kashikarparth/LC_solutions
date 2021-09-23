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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        
        int count = 0;
        ListNode* temp = head;
        
        while(head and head->next and head->next->val == head->val){
            temp = head;
            while(temp and temp->val == head->val){
            temp = temp->next; count++;
            }
            if(count!=1){
                head = temp;
            }
            if(!head) return head;
            if(!head->next) return head;
        }
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        
        while(curr){
            
            count = 0;
            while(curr and curr->val == prev->next->val){
                curr = curr->next;
                count++;
            }
            if(count == 1){
                prev = prev->next;
                curr = prev->next;
            }
            else{
                prev->next = curr;
            }
        }
        
        return head;
    }
};