'''
19. Remove Nth Node From End of List

Given the head of a linked list, remove the nth node from the end of the list and return its head.



'''


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        l = 0
        temp = head
        s  = head
        while(temp!=None):
            l+=1
            temp = temp.next
        if l ==1 or l== 0:
            return None
        if l== n:
            return head.next
        e = l - n
        print(e,l)
        c = 0
        while s!= None and c<e-1:
            s  = s.next
            c+=1
        print(c)
        s.next = s.next.next
        return head
        
