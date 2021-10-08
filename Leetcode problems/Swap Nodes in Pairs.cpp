//question :-"https://leetcode.com/problems/swap-nodes-in-pairs"


class Solution {
public:
   ListNode* swapPairs(ListNode* head) {
        ListNode* temp = head;
        while (temp != NULL && temp->next != NULL){
            swap(temp->val,temp->next->val);
            temp = temp->next->next;
           
        }
        return head;
    }
};
