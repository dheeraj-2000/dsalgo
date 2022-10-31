// Problem Link :  https://leetcode.com/problems/sort-list/
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
// A linked list is a data structure where the objects are arranged in a linear order. Unlike an array, however, in which the linear order is determined by the array indices, the order in a linked list is determined by a pointer in each object.
class Solution
{
public:
    // Merge Sort Approach
    ListNode *merge(ListNode *l1, ListNode *l2)
    {
        ListNode *ptr = new ListNode(INT_MIN);
        ListNode *p = ptr;
        // Merging two linked lists
        while (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                p->next = l1;
                l1 = l1->next;
            }
            else
            {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        // If the linked lists are unequal
        while (l1)
        {
            p->next = l1;
            l1 = l1->next;
            p = p->next;
        }
        while (l2)
        {
            p->next = l2;
            l2 = l2->next;
            p = p->next;
        }
        return ptr->next;
    }
    ListNode *sortList(ListNode *head)
    {
        // If there's 0 or 1 node in the Linked List return head directly
        if (head == NULL || head->next == NULL)
            return head;

        // Finding the mid of the linked list and dividing the linked list into two halves
        ListNode *slow = head, *fast = head, *p = NULL;
        while (fast && fast->next)
        {
            p = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        p->next = NULL;

        // Passing the two divided linked lists to the sortList
        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(slow);

        // Merging the sorted linked list parts in a sorted manner to form a sorted linked list
        return merge(l1, l2);
    }
};