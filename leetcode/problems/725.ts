/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

const splitListToParts = (
  head: ListNode | null,
  k: number
): Array<ListNode | null> => {
  const ans = Array(k).fill(null)
  let n = 0,
    p = head
  while (p) {
    n++
    p = p.next
  }
  const blo = Math.floor(n / k),
    rem = n % k
  p = head
  for (let i = 0; i < k && p; i++) {
    let q = p
    ans[i] = q
    const m = blo + (i < rem ? 1 : 0)
    for (let j = 0; j < m - 1; j++) {
      q = q.next
    }
    let next = q.next
    q.next = null
    p = next
  }
  return ans
}
