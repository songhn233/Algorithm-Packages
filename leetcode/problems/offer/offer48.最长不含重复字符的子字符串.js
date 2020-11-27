const lengthOfLongestSubstring = (s) => {
  if (!s.length) return 0
  let ans = 1,
    l = 0,
    r = 0
  const map = new Map()
  map.set(s[0], (map.has(s[0]) ? map.get(s[0]) : 0) + 1)
  for (r = 1; r < s.length; r++) {
    while (map.has(s[r]) && map.get(s[r])) {
      map.set(s[l], (map.has(s[l]) ? map.get(s[l]) : 0) - 1)
      l++
    }
    map.set(s[r], (map.has(s[r]) ? map.get(s[r]) : 0) + 1)
    if (l <= r) ans = Math.max(ans, r - l + 1)
  }
  return ans
}
