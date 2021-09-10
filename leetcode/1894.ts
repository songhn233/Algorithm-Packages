function chalkReplacer(chalk: number[], k: number): number {
  const n = chalk.length,
    sum = Array(n).fill(0)
  let tot = (sum[0] = chalk[0])
  for (let i = 1; i < n; i++) {
    sum[i] = sum[i - 1] + chalk[i]
    tot += chalk[i]
  }
  k %= tot
  let l = 0,
    r = n - 1
  while (l < r) {
    let mid = (l + r) >> 1
    if (sum[mid] > k) r = mid
    else l = mid + 1
  }
  return l
}
