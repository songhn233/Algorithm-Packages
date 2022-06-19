func sellingWood(m int, n int, prices [][]int) int64 {
  f := make([][]int, m + 1)
  max := func(a, b int) int {
    if a > b {
      return a
    }
    return b
  }
  for i := range f {
    f[i] = make([]int, n + 1)
  }
  for _, v := range prices {
    f[v[0]][v[1]] = v[2]
  }
  for i := 1; i <= m; i += 1 {
    for j := 1; j <= n; j += 1 {
      for k := 1; k < i; k ++ {
        f[i][j] = max(f[i][j], f[k][j] + f[i - k][j])
      }
      for k := 1; k < j; k ++ {
        f[i][j] = max(f[i][j], f[i][k] + f[i][j - k])
      }
    }
  }
  return int64(f[m][n])
}
