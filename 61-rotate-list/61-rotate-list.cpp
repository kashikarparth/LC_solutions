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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(!head) return head;
        
        int length = 0;
        ListNode* tmp = head;
        while(tmp){
            length++;
            tmp = tmp->next;
        }
        k%=length;
        
        if(!k) return head;
        
        ListNode* fast = head;
        ListNode* slow = head;
        int t = k;
        
        while(t--){
            fast = fast->next;
        }
        
        while(fast){
            fast = fast->next;
            slow = slow->next;
        }
        
        ListNode* anchor = head;
        while(anchor->next!=slow){
            anchor = anchor->next;
        }
        anchor->next= NULL;
        
        ListNode* start = slow;
        while(slow->next){
            slow = slow->next;
        }
        slow->next = head;
        
        head = start;
        return head;
    }
};