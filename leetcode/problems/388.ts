function lengthLongestPath(input: string): number {
  const files = input.split('\n')
  const s: number[] = [0]
  let ans = 0
  files.forEach((v) => {
    const cnt = v.lastIndexOf('\t') + 1
    while (cnt + 1 < s.length) {
      s.pop()
    }
    const length = s[s.length - 1] + (v.length - cnt + 1)
    s.push(length)
    if (v.includes('.')) {
      ans = Math.max(ans, length - 1)
    }
  })
  return ans
}
