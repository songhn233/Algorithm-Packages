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

function reverseList(head: ListNode | null): ListNode | null {
  if (head === null) return head
  let p = new ListNode(),
    q = new ListNode()
  q = null
  while (true) {
    p = head.next
    head.next = q
    if (p === null) break
    q = head
    head = p
  }
  return head
}
