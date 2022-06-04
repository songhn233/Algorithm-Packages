/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
const twoSum = function (nums, target) {
  const map = new Map()
  let ans = []
  for (let [index, val] of nums.entries()) {
    if (map.has(target - val)) {
      ans = [index, map.get(target - val)]
      break
    }
    map.set(val, index)
  }
  return ans
};
