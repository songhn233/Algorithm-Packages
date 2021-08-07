const abs = a => Math.abs(a)
const min = (a, b) => a > b ? b : a

const search = (nums, a) => {
  let l = 0, r = nums.length;
  while (l < r) {
    let mid = (l + r) >> 1;
    if (nums[mid] > a) {
      r = mid
    } else l = mid + 1
  }
  return l
}

/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
const minAbsoluteSumDiff = (nums1, nums2) => {
  let ans = nums1.reduce((acc, _, i) => acc + Math.abs(nums1[i] - nums2[i]), 0)
  const sum = ans
  const nums = nums1.slice().sort((a, b) => a - b)
  for (let i = 0; i < nums2.length; i++) {
    let t = search(nums, nums2[i]);
    if (t < nums1.length) {
      ans = min(ans, sum - abs(nums1[i] - nums2[i]) + abs(nums[t] - nums2[i]))
    }
    if (t > 0) {
      ans = min(ans, sum - abs(nums1[i] - nums2[i]) + abs(nums[t - 1] - nums2[i]))
    }
  }
  return ans % (1e9 + 7);
};