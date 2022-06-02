func lengthOfLongestSubstring(s string) int {
  ans := 0
  m := map[byte]int{}
  n := len(s)
  for l, r := 0, 0; r < n; r ++ {
    m[s[r]] += 1
    for m[s[r]] > 1 {
      m[s[l]] -= 1
      l ++
    }
    ans = max(ans, r - l + 1)
  }
  return ans
}

func max(x, y int) int {
    if x < y {
        return y
    }
    return x
}