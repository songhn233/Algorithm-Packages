function reverseKGroup(head: ListNode | null, k: number): ListNode | null {
  let h = new ListNode(),
    t = null,
    ans = h
  h.next = head
  let p = head
  while (p) {
    let end = p,
      i = 1
    while (end && i++ < k) {
      end = end.next
    }
    if (!end) {
      break
    }
    t = end.next
    let start = p,
      pre = null
    end.next = null
    while (p) {
      const tmp = p.next
      p.next = pre
      pre = p
      p = tmp
    }
    start.next = t
    h.next = end

    h = start
    p = t
  }
  return ans.next
}
