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
      ListNode* curr1 = l1;
      ListNode* curr2 = l2;
      int c_in = 0;
      int c_out = 0;
      bool return_l1;
      ListNode* conti;
      ListNode* previous;
      while(curr1!=NULL && curr2!=NULL){
        c_in = c_out;
        c_out = (curr1->val+curr2->val+c_in)/10;
        curr1->val = (curr1->val + curr2->val + c_in)%10;
        curr2->val = curr1->val;
        previous = curr1;
        curr1 = curr1->next;
        curr2 = curr2->next;
      }
      if(curr1 == NULL && curr2 != NULL){
        conti = curr2;
        return_l1 = false;
      }
      else if(curr1 != NULL && curr2 == NULL){
        conti = curr1;
        return_l1 = true;
      }
      else{
        if(c_out != 0)  previous->next = new ListNode(1);
        return l1;
      }
      while(conti!=NULL){
        c_in = c_out;
        c_out = (conti->val+c_in)/10;
        conti->val = (conti->val + c_in)%10;
        if(conti->next == NULL && c_out != 0){
          conti->next = new ListNode(1);
          break;
        }
        conti = conti->next;
      }
      return return_l1?l1:l2;
    }
};
