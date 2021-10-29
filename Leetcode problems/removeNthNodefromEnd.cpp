// problem: https://leetcode.com/problems/remove-nth-node-from-end-of-list/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* start = new ListNode();
        start->next = head;
        ListNode* last = start;
        ListNode* last_prev = start;
        
        for(int i=1;i<=n;i++){     // Keep iterating till last reaches to n
            last = last->next;
        }
        while(last->next != NULL)  // Keep iterating both last and last_prev till last reaches to null(means it's the last element.)
        {
            last = last->next;
            last_prev = last_prev->next;
        }
        last_prev->next = last_prev->next->next;  // remove link to next and assign next to next.
        return start->next;
    }
};