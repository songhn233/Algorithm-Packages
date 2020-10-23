/*
 * @lc app=leetcode.cn id=234 lang=javascript
 *
 * [234] 回文链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {boolean}
 */
const isPalindrome = (head) => {
  const list = []
  if (!head) {
    return head
  }
  let p = head
  while (p) {
    list.push(p)
    p = p.next
  }
  let i = 0,
    j = list.length - 1
  while (i < j) {
    if (list[i].val !== list[j].val) {
      return false
    }
    i++, j--
  }
  return true
}
// @lc code=end
