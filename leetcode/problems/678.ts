function checkValidString(s: string): boolean {
  const sta: number[] = [],
    star: number[] = []
  for (let i = 0; i < s.length; i++) {
    const c = s[i]
    if (c === '(') {
      sta.push(i)
    }
    if (c === '*') {
      star.push(i)
    }
    if (c === ')') {
      if (sta.length) {
        sta.pop()
      } else if (star.length) {
        star.pop()
      } else {
        return false
      }
    }
  }

  while (sta.length && star.length) {
    const a = sta.pop(),
      b = star.pop()
    if (a > b) return false
  }
  return !sta.length
}
