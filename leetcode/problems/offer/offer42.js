/**
 * @param {number[]} nums
 * @return {number}
 */
const maxSubArray = (nums) => {
  let ans = nums[0], sum = 0;
  nums.forEach(v => {
    if (sum < 0) sum = 0;
    sum += v;
    ans = Math.max(ans, sum);
  })
  return ans;
}