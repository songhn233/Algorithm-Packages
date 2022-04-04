function swapPairs(head: ListNode | null): ListNode | null {
  head = new ListNode(0, head)
  let p = head.next,
    q = head
  while (p && p.next) {
    q.next = p.next
    const tmp = p.next.next
    p.next.next = p
    p.next = tmp
    q = p
    p = tmp
  }
  return head.next
}
