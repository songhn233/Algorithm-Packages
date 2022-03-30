function generateMatrix(n: number): number[][] {
  let len = n - 1,
    time = Math.floor(n / 2)
  let sx = 0,
    sy = 0,
    x = 0,
    y = 0,
    num = 1
  const ans = Array(n)
    .fill(0)
    .map(() => Array(n).fill(0))
  while (time--) {
    ;(x = sx), (y = sy)
    while (x - sx < len) {
      ans[y][x++] = num++
    }
    while (y - sy < len) {
      ans[y++][x] = num++
    }
    while (x > sx) {
      ans[y][x--] = num++
    }
    while (y > sy) {
      ans[y--][x] = num++
    }
    ++sx, ++sy
    len -= 2
  }
  if (n & 1) {
    ans[sx][sy] = num
  }
  return ans
}
