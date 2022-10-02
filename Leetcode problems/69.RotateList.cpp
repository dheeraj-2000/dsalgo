/*Leetcode Problem : 61. Rotate List
Given the head of a linked list, rotate the list to the right by k places.
Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:*/

/*
Explanation
The problem mentions rotating the list to the right. We first have to get the total number of nodes in the list. If k is greater than the list length, we first take the modulo of k by list length and then subtract the value of k from the list length. If k is smaller, we subtract the value of k from the list length.

Note: If the problem mentioned left rotation, we won't subtract k by the length of the list.

Algorithm:

empty list
- if head == null
  - return head

- set ListNode *p = head
  set listLength = 1

- loop while p->next != null
  - update p = p->next
  - increment listLength++

- if k > listLength
  - k = k % listLength

- k = listLength - k

- if k == 0 || k == listLength
  - return head

- set ListNode *current = head

- loop while k > 1 && current != null
  - update current = current->next
  - decrement k--

- if current == null
  - return head

- update p->next = head
  update head = current->next
  update current->next = null

- return head

*/


//C++ solution for rotate List
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head){
            return head;
        }

        ListNode *p = head;
        int listLength = 1;

        while(p->next != NULL){
            p = p->next;
            listLength++;
        }

        if(k > listLength) {
            k = k % listLength;
        }

        k = listLength - k;

        if(k == 0 || k == listLength) {
            return head;
        }

        ListNode *current = head;

        while(k > 1 && current != NULL){
            current = current->next;
            k--;
        }

        if(current == NULL){
            return head;
        }

        p->next = head;
        head = current->next;
        current->next = NULL;

        return head;
    }
};
