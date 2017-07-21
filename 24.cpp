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
    ListNode* swapPairs(ListNode* head) {
      if(head == NULL || head->next == NULL)  return head;
      ListNode* previous = NULL;
      ListNode* first = head;
      ListNode* second = head->next;
      bool first_time = true;
      while(first != NULL){
        second = first->next;
        if(second == NULL)  break;
        first->next= second->next;
        second->next = first;
        if(first_time)   head = second;
        else    previous->next = second;
        previous = first;
        first = first->next;
        first_time = false;
      }
      return head;
    }
};
