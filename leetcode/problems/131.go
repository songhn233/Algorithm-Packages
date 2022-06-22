func partition(s string) [][]string {
  var ans [][]string
  check := func(i int, j int) bool {
    str := s[i:j+1]
    x, y := 0, len(str)-1
    for x < y {
      if str[x] != str[y] {
        return false
      }
      x ++
      y --
    }
    return true
  }
  var dfs func([]string, int)
  dfs = func(tmp []string, cur int) {
    if cur >= len(s) {
      ans = append(ans, append([]string(nil), tmp...))
      return
    }
    for i := cur; i < len(s); i ++ {
      if check(cur, i) {
        tmp = append(tmp, s[cur:i+1])
        dfs(tmp, i+1)
        tmp = tmp[:len(tmp)-1]
      }
    }
  }
  dfs([]string{}, 0)
  return ans
}