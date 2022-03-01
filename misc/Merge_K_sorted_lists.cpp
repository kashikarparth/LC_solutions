class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

      ListNode* head = new ListNode(0);
      ListNode* ptr = head;
      priority_queue<pair<int, ListNode*>> q;

      for (ListNode* n: lists) {
        if(n) {
          q.push({ -1*n->val, n }); 
        }
      }
      
	  
      while(!q.empty()) {
        pair<int, ListNode*> p = q.top();
        q.pop();
        ptr->next = new ListNode(-1*p.first); 
        ptr = ptr->next;
        ListNode* x = p.second;
        if(x->next) {
          q.push({ -1* x->next->val, x->next });
        }
      }
      
      return head->next;
    }
};