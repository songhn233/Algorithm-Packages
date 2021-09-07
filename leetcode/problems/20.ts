function isValid(s: string): boolean {
  const map = new Map([
    [')', '('],
    [']', '['],
    ['}', '{'],
  ])
  const sta = []
  for (let a of s) {
    if (map.has(a)) {
      if (!sta.length || sta[sta.length - 1] !== map.get(a)) {
        return false
      }
      sta.pop()
    } else {
      sta.push(a)
    }
  }
  return !sta.length
}
