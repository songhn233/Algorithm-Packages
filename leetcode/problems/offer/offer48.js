/**
 * @param {string} s
 * @return {number}
 */
const lengthOfLongestSubstring = (s) => {
  const map = new Map()
  let last = 0, ans = 0;
  const arr = s.split('')
  for (let [index, val] of s.split('').entries()) {
    while (map.has(val) && map.get(val) > 0 && last < index) {
      map.set(arr[last], map.get(arr[last]) - 1)
      last++
    }
    map.set(val, (isNaN(map.get(val)) ? 0 : Number(map.get(val))) + 1)
    ans = (index - last + 1) > ans ? (index - last + 1) : ans
  }
  return ans
};