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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      if(head->next == NULL && n==1)  return NULL;
      ListNode* previous = NULL;
      ListNode* start = head;
      ListNode* end = start;
      for(int i=0; i<n-1; i++){
        end = end->next;
      }
      while(end->next != NULL){
        previous = start;
        start = start->next;
        end = end->next;
      }
      if(previous)    previous->next = start->next;
      else    head = start->next;
      return head;
    }
};
