/*
 * @lc app=leetcode.cn id=143 lang=javascript
 *
 * [143] 重排链表
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
 * @return {void} Do not return anything, modify head in-place instead.
 */
const reorderList = (head) => {
  const arr = []
  let p = head
  while (p) {
    arr.push(p)
    p = p.next
  }
  const h = new ListNode()
  p = h
  for (let i = 0; i < arr.length; i++) {
    if (i % 2 == 0) {
      p.next = arr[Math.floor(i / 2)]
    } else {
      p.next = arr[arr.length - Math.floor(i / 2) - 1]
    }
    p = p.next
  }
  p.next = null
  return h.next
}
// @lc code=end
