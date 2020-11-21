/*
 * @lc app=leetcode.cn id=148 lang=javascript
 *
 * [148] 排序链表
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
const sortList = (head) => {
  let list = []
  let p = head
  while (p) {
    list.push(p)
    p = p.next
  }
  list = list.sort((a, b) => {
    if (a.val < b.val) return -1
    return 1
  })
  const h = new ListNode()
  p = h
  list.forEach((v) => {
    const newNode = new ListNode()
    newNode.val = v.val
    p.next = newNode
    p = p.next
  })
  return h.next
}
// @lc code=end
