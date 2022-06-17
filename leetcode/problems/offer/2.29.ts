/**
 * @param {Node} head
 * @param {number} insertVal
 * @return {Node}
 */
const insert = function (head, insertVal) {
  let p = head,
    start = null
  const ins = (a, b) => {
    const t = new Node(insertVal, b)
    a.next = t
  }
  if (head === null) {
    const t = new Node(insertVal)
    t.next = t
    return t
  } else if (head.next === head) {
    ins(head, head)
    return head
  }
  while (1) {
    if (start) {
      if (p.next.val >= insertVal || p.next === start) {
        ins(p, p.next)
        break
      }
    }
    if (p.next === head && !start) {
      start = head
      if (head.val >= insertVal) {
        ins(p, head)
        break
      }
    }
    if (!start && p.next.val < p.val) {
      start = p.next
      if (start.val >= insertVal) {
        ins(p, start)
        break
      }
    }
    p = p.next
  }
  return head
}
