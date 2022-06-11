func findAndReplacePattern(words []string, pattern string) []string {
  var ans []string
  vertify := func(a string, b string) bool {
    mp := map[rune]byte{}
    for i, v := range a {
      t := b[i]
      if _, ok := mp[v]; ok == false {
        mp[v] = t
      } else {
        if mp[v] != t {
          return false
        }
      }
    }
    return true
  }
  for _, s := range words {
    if vertify(s, pattern) && vertify(pattern, s) {
      ans = append(ans, s)
    }
  }
  return ans
}