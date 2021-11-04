const longestSubsequence = (arr: number[], difference: number) => {
  const map = new Map()
  let ans = 1
  for (let v of arr) {
    map.set(v, (map.has(v - difference) ? map.get(v - difference) : 0) + 1)
    ans = Math.max(ans, map.get(v))
  }
  return ans
}
