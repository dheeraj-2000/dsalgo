/*
  Link to problem: https://leetcode.com/problems/split-linked-list-in-parts/
  Difficulty: Medium
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getlength(ListNode* head)
    {
        ListNode* h1=head;
        int s=0;
        while(h1!=NULL)
        {
            s++;
            h1=h1->next;
        }
        return s;
    }
    
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        vector<ListNode*> v(k, NULL);    //create a 'vector of pointers' of size k pointing to NULL
        if (k == 1)                      //if number of parts in which linked list is to be divided == 1
        {
            v[0] = head;
            return v;
        }
        
        int n = getlength(head);         //size of linked list
        ListNode* pre = NULL;
        for (int i = 0; i < k; i++) 
        {
            v[i] = head;
            int j = n/k;        //size of each list after splitting
            if(i < n%k)         //for first n%k lists
                j++;
            while (head != NULL && j) 
            {
                pre = head;
                head = head->next;
                j--;
            }
            if (pre != NULL) 
                pre->next = NULL;
        }
        return v;        
    }
};
