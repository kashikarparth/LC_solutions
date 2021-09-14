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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* turtle = head;
        ListNode* saviour = head;
        ListNode* fast = head;

        while(n){
            fast = fast->next;
            n--;
        }
        while(fast){
            turtle = turtle ->next;
            fast = fast -> next;
        }
        
        if(saviour == turtle) return head->next;
        
        while(saviour -> next != turtle){
            saviour = saviour->next;
        }
        saviour->next = turtle->next;
        return head;
    }
};