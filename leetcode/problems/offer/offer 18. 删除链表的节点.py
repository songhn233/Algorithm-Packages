# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    def deleteNode(self, head: ListNode, val: int) -> ListNode:
        newHead = ListNode()
        newHead.next = head
        p = newHead
        while p.next:
            if p.next.val == val:
                p.next = p.next.next
                break
            p = p.next
        return newHead.next
