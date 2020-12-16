# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getKthFromEnd(self, head: ListNode, k: int) -> ListNode:
        p = head
        for i in range(k - 1):
            p = p.next
        q = head
        while p.next:
            p = p.next
            q = q.next
        return q
