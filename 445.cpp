/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      stack<ListNode*> s1;
      stack<ListNode*> s2;
      ListNode* curr = l1;
      while(curr){
        s1.push(curr);
        curr = curr->next;
      }
      curr = l2;
      while(curr){
        s2.push(curr);
        curr = curr->next;
      }
      ListNode * previous = nullptr;
      ListNode* current;
      int c_in = 0;
      while(!s1.empty() && !s2.empty()){
        int current_sum = (s1.top()->val + s2.top()->val + c_in);
        current = new ListNode(current_sum%10);
        if(current_sum >= 10)   c_in = current_sum/10;
        else c_in = 0;
        s1.pop();
        s2.pop();
        current->next = previous;
        previous = current;
      }
      while(!s1.empty()){
        int current_sum = (s1.top()->val+c_in);
        current = new ListNode(current_sum%10);
        if(current_sum >= 10)   c_in = current_sum/10;
        else c_in = 0;
        s1.pop();
        current->next = previous;
        previous = current;
      }
      while(!s2.empty()){
        int current_sum = (s2.top()->val+c_in);
        current = new ListNode(current_sum%10);
        if(current_sum >= 10)   c_in = current_sum/10;
        else c_in = 0;
        s2.pop();
        current->next = previous;
        previous = current;
      }
      if(c_in != 0){
        current = new ListNode(c_in);
        current->next = previous;
      }
      return current;
    }
};
