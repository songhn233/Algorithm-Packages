/*
 * @lc app=leetcode.cn id=18 lang=javascript
 *
 * [18] 四数之和
 */

// @lc code=start
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[][]}
 */
var fourSum = function(nums, target) {
  nums.sort((a, b) => a - b);
  const ans = [];
  for (let i = 0; i < nums.length; i ++) {
    for (let j = i + 1; j < nums.length; j ++) {
      const t = target - nums[i] - nums[j];
      let x = j + 1, y = nums.length - 1;
      for (; x < y; x ++ ) {
        while(nums[x] + nums[y] > t && y > x) y --;
        if(nums[x] + nums[y] === t && y > x) {
          while(nums[x] == nums[x + 1]) x ++;
          while(nums[y] === nums[y - 1]) y --;
          const temp = [];
          temp.push(nums[i]);
          temp.push(nums[j]);
          temp.push(nums[x]);
          temp.push(nums[y]);
          ans.push(temp);
        }
      }
      while(nums[j] == nums[j + 1]) j ++;
    }
    while(nums[i] == nums[i + 1]) i ++;
  }
  return ans;
};
// @lc code=end

