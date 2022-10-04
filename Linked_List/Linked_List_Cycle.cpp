/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 
 leetcode problem 142 : Linked List Cycle II 
 */
 
 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL){
            return head;
        }
        
        ListNode* temp = head;
        map<ListNode*,bool> visited;
        
        while(temp!=NULL){
            if(visited[temp]==true){
                return temp;
            }
            visited[temp]= true;
            temp = temp->next;
        }
        
        return NULL;
    }
};
