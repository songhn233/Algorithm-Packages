function reformat(s: string): string {
  let s1 = s.split('').filter((v) => !isNaN(Number(v)))
  let s2 = s.split('').filter((v) => isNaN(Number(v)))
  if (Math.abs(s1.length - s2.length) > 1) {
    return ''
  }
  if (s1.length > s2.length) {
    ;[s1, s2] = [s2, s1]
  }
  let ans = ''
  for (let i = 0; i < s1.length; i++) {
    ans += s2[i] + s1[i]
  }
  if (s2.length > s1.length) {
    ans += s2[s2.length - 1]
  }
  return ans
}
