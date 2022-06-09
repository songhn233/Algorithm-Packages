function removeNthFromEnd(head: ListNode | null, n: number): ListNode | null {
  let h = new ListNode(0, head)
  let count = 0,
    q = h,
    v = h
  while (q) {
    q = q.next
    if (count <= n) {
      count++
    } else {
      v = v.next
    }
  }
  v.next = v.next.next
  return h.next
}
