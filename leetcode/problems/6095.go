func strongPasswordCheckerII(password string) bool {
  flag := make([]bool, 6)
  flag[5] = true
  if len(password) >= 8 {
    flag[0] = true
  }
  for i, v := range password {
    if v >= 'a' && v <= 'z' {
      flag[1] = true
    }
    if v >= 'A' && v <= 'Z' {
      flag[2] = true
    }
    if v >= '0' && v <= '9' {
      flag[3] = true
    }
    if strings.Index("!@#$%^&*()-+", string(v)) != -1 {
      flag[4] = true
    }
    if i > 0 && password[i] == password[i - 1] {
      flag[5] = false
    }
  }
  ans := true
  for _, v := range flag {
    if v == false {
      ans = false
    }
  }
  return ans
}