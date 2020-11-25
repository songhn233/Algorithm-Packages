/*
 * @lc app=leetcode.cn id=1024 lang=javascript
 *
 * [1024] 视频拼接
 */

// @lc code=start
/**
 * @param {number[][]} clips
 * @param {number} T
 * @return {number}
 */
const videoStitching = (clips, T) => {
  const t = new Array(100).fill(0)
  for (let i = 0; i < clips.length; i++) {
    if (clips[i][0] < T) {
      t[clips[i][0]] = Math.max(t[clips[i][0]], clips[i][1])
    }
  }
  let pos = 0,
    ans = 0,
    pre = 0
  for (let i = 0; i < T; i++) {
    pos = Math.max(pos, t[i])
    if (pos === i) {
      return -1
    }
    if (i === pre) {
      pre = pos
      ans++
    }
  }
  return ans
}

// @lc code=end
