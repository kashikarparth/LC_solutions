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
    ListNode* swapPairs(ListNode* head) {
        
        ListNode* first = head;
        ListNode* second = NULL;
        ListNode* third = NULL;
        ListNode* prev = NULL;
        
        if(!first) return NULL;
        
        ListNode* temp = head->next;
        
        if(!temp) return head;
        
        while(first){
            
            second = first->next;
            
            if(!second) return temp;
            
            third = second->next;
            second->next = first;
            
            first->next = third;
            
            if(prev) prev->next = second;
            
            prev = first;
            first = third;
        }
        
        return temp;
    }
};