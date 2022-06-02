func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
  p := &ListNode{}
  head, last := p, 0
  for l1 != nil || l2 != nil {
    n1, n2 := 0, 0
    if l1 != nil {
      n1 += l1.Val
      l1 = l1.Next
    }
    if l2 != nil {
      n2 += l2.Val
      l2 = l2.Next
    }
    sum := n1 + n2 + last
    sum, last = sum % 10, sum / 10
    cur := &ListNode{Val: sum}
    p.Next = cur
    p = cur
  }
  if last != 0 {
    p.Next = &ListNode{Val: last}
  }
  return head.Next
}