function isValid(s) {
  const m = {
    '(': ')',
    '[': ']',
    '{': '}',
  }
  const sta = []
  for (const v of s) {
    if (m[v]) {
      sta.push(v)
    } else if (sta.length && v === m[sta[sta.length - 1]]) {
      sta.pop()
    } else {
      return false
    }
  }
  return !sta.length
}
