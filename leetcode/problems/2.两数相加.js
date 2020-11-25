/*
 * @lc app=leetcode.cn id=2 lang=javascript
 *
 * [2] 两数相加
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
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
const addTwoNumbers = (l1, l2) => {
  const root = new ListNode();
  let t = 0;
  let p = root;
  while(l1 || l2) {
    t += l1 ? l1.val : 0;
    t += l2 ? l2.val : 0;
    const temp = new ListNode(t % 10);
    t = parseInt(t / 10);
    p.next = temp;
    p = temp;
    l1 = l1 ? l1.next : l1;
    l2 = l2 ? l2.next : l2;
  }
  t && (p.next = new ListNode(t));
  return root.next;
};
// @lc code=end

