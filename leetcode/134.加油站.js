/*
 * @lc app=leetcode.cn id=134 lang=javascript
 *
 * [134] 加油站
 */

// @lc code=start
/**
 * @param {number[]} gas
 * @param {number[]} cost
 * @return {number}
 */
const canCompleteCircuit = (gas, cost) => {
  let pos = 0
  const n = gas.length
  while (pos < n) {
    let sum = 0,
      i = 0
    for (i = 0; i < n; i++) {
      sum += gas[(pos + i) % n] - cost[(pos + i) % n]
      if (sum < 0) {
        break
      }
    }
    if (i === n) {
      return pos
    } else {
      pos += i + 1
    }
  }
  return -1
}
// @lc code=end
