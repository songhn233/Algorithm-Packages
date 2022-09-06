const rotateString = (s: string, goal: string) => {
  if (s.length !== goal.length) return false
  const n = s.length,
    m = goal.length
  for (let i = 0; i < n; i++) {
    let flag = true
    for (let j = 0; j < m; j++) {
      if (s[(i + j) % n] === goal[j]) continue
      flag = false
      break
    }
    if (flag) {
      return true
    }
  }
  return false
}
