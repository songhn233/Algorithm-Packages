function removeElements(head: ListNode | null, val: number): ListNode | null {
  head = new ListNode(0, head)
  let pre = head,
    cur = head.next
  while (cur) {
    if (cur.val === val) {
      pre.next = cur.next
    } else {
      pre = pre.next
    }
    cur = cur.next
  }
  return head.next
}
