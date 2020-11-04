// Problem Statement: Link -> https://www.interviewbit.com/problems/subtract/
// Given a singly linked list, modify the value of first half nodes such that :

// 1st node’s new value = the last node’s value - first node’s current value
// 2nd node’s new value = the second last node’s value - 2nd node’s current value,
// and so on …

// Input: 1 -> 2 -> 3 -> 4 -> 5
// Output: 4 -> 2 -> 3 -> 4 -> 5


/* Solution:
1. Reverse the 2nd half of LinkedList
2. Traverse both 1st & 2nd half parallely & update the values in 1st half of the list
3. Then reverse 2nd half again, to bring it back to its orignal order.
*/
ListNode* reverse(ListNode* head){
    
    ListNode* ptr = head;
    ListNode* temp = NULL;
    ListNode* prev = NULL;
    
    while(ptr != NULL){
        temp = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = temp;
    }
    
    return prev;
}


ListNode* Solution::subtract(ListNode* head) {
    
    int count = 0;
    
    ListNode* ptr = head;
    while(ptr!= NULL){
        count++;
        ptr = ptr->next;
    }
    
    ptr = head;
    
    for(int i =1; i<count/2; i++){
        ptr = ptr->next;
    }
    
    ListNode* rev = reverse(ptr->next);
    ptr->next = NULL;
    ListNode* end = ptr;
    
    ptr = head;
    ListNode* rptr = rev;
    
    while(ptr != NULL){
        ptr->val = (rptr->val - ptr->val);
        ptr = ptr->next;
        rptr = rptr->next;
    }
    
    rptr = reverse(rev);
    end->next = rptr;
    return head;
}
