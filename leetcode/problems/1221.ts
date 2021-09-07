function balancedStringSplit(s: string): number {
  let ans = 0,
    t = 0
  for (let i = 0; i < s.length; i++) {
    s[i] === 'R' ? ++t : --t
    if (!t) {
      ans++
      t = 0
    }
  }
  return ans
}
