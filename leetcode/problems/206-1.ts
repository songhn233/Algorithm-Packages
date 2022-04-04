function reverseList(head: ListNode | null): ListNode | null {
  let p = null,
    q = head
  while (q) {
    const tmp = q.next
    q.next = p
    p = q
    q = tmp
  }
  return p
}
