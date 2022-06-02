func myAtoi(s string) int {
  value, signal, i := 0, 1, 0
  s = strings.TrimSpace(s)
  if len(s) > 0 {
    if s[0] == '-' {
      signal = -1
      i ++
    } else if s[0] == '+' {
      i ++
    }
  }
  for i < len(s) {
    if s[i] < '0' || s[i] > '9' {
      break
    }
    value = value * 10 + int(s[i] - '0')
    if value * signal < math.MinInt32 {
      return math.MinInt32
    }
    if(value * signal > math.MaxInt32) {
      return math.MaxInt32
    }
    i ++
  }
  return value * signal
}