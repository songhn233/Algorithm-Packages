function minFlipsMonoIncr(s: string): number {
  const n = s.length,
    sum = Array(n).fill(0)
  sum[0] = s[0].charCodeAt(0) - '0'.charCodeAt(0)
  for (let i = 1; i < n; i++) {
    sum[i] = sum[i - 1] + s[i].charCodeAt(0) - '0'.charCodeAt(0)
  }
  let ans = Infinity
  for (let i = 0; i < n; i++) {
    if (i === 0) {
      ans = Math.min(ans, n - sum[n - 1], sum[n - 1])
    } else {
      ans = Math.min(ans, 2 * sum[i - 1] + n - i - sum[n - 1])
    }
  }
  return ans
}
