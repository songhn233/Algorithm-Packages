/*
 * @lc app=leetcode.cn id=24 lang=javascript
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
const swapPairs = (head) => {
  const root = new ListNode()
  root.next = head
  let p = root
  while (p.next && p.next.next) {
    const t1 = p.next.next.next,
      t2 = p.next
    p.next = p.next.next
    p.next.next = t2
    p.next.next.next = t1
    p = p.next.next
  }
  return root.next
}
// @lc code=end
