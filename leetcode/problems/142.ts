const detectCycle = function (head: ListNode | null) {
  let slow = head,
    fast = head
  while (fast && fast.next) {
    slow = slow.next
    fast = fast.next.next
    if (fast === slow) {
      let tmp = head
      while (tmp !== slow) {
        tmp = tmp.next
        slow = slow.next
      }
      return tmp
    }
  }
  return null
}
