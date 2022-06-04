func buddyStrings(s string, goal string) bool {
  if len(s) != len(goal) {
    return false
  }
  var a, b, c, d string
  flag, m := false, map[byte]int{}
  for i := range s {
    m[s[i]] ++
    if m[s[i]] > 1 {
      flag = true
    }
    if s[i] != goal[i] {
      if a == "" {
        a = string(s[i])
        c = string(goal[i])
      } else if b == "" {
        b = string(s[i])
        d = string(goal[i])
      } else {
        return false
      }
    }
  }
  if a == "" {
    if flag {
      return true
    }
    return false
  }
  if a == d && b == c {
    return true
  }
  return false
}