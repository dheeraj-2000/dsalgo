// problem: https://leetcode.com/problems/reverse-nodes-in-k-group/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
   
    ListNode* reverseKGroup(ListNode* A, int B) {
         if(!A)
        return NULL;
        ListNode* t = A;
        for(int i=0;i<B;i++){
            if(t==NULL) 
                return A;
            t=t->next;
        }
        ListNode* curr = A;
        ListNode* prev = NULL;
        ListNode* sec = NULL;
        int count=0;
        while(curr && count<B){
            sec = curr->next;
            curr->next = prev;
            prev = curr;
            curr = sec;
            count++;
        }
        if(sec)
            A->next = reverseKGroup(sec,B);
        return prev;
    }
};