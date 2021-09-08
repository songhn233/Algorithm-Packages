function getKthFromEnd(head: ListNode | null, k: number): ListNode | null {
  let fast = head,
    slow = head
  while (fast && k) {
    ;[fast, k] = [fast.next, k - 1]
  }
  while (fast) {
    ;[fast, slow] = [fast.next, slow.next]
  }
  return slow
}
