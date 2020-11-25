/*
 * @lc app=leetcode.cn id=141 lang=javascript
 *
 * [141] 环形链表
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
const hasCycle = head => {
  const map = new Map();
  while(head) {
    if (map.get(head)) {
      return true;
    }
    map.set(head, true);
    head = head.next;
  }
  return false;
};
// @lc code=end

