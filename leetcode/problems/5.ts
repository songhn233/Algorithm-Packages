const longestPalindrome = (s: string): string => {
  const n = s.length
  const f: boolean[][] = Array(n)
    .fill(0)
    .map((_: any[]) => Array(n).fill(false))
  let ans = 0
  let arr = [0, 0]
  for (let i = 0; i < n; i++) f[i][i] = true
  for (let d = 2; d <= n; d++) {
    for (let i = 0; i < n - d + 1; i++) {
      let j = i + d - 1
      if (s[i] === s[j]) {
        if (j - i + 1 <= 3) {
          f[i][j] = true
        } else {
          f[i][j] = f[i + 1][j - 1]
        }
      }
      if (f[i][j] && j - i + 1 > ans) {
        ans = j - i + 1
        arr = [i, j]
      }
    }
  }
  return s.slice(arr[0], arr[1] + 1)
}
