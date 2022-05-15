const maximumWhiteTiles = (tiles: number[][], carpetLen: number) => {
  tiles.sort((a, b) => a[0] - b[0])
  const n = tiles.length
  let ans = 0,
    l = 0,
    r = 0,
    tmp = 0
  while (r < n) {
    if (tiles[r][1] - tiles[l][0] + 1 <= carpetLen) {
      tmp += tiles[r][1] - tiles[r][0] + 1
      ans = Math.max(ans, tmp)
      ++r
    } else {
      if (tiles[r][0] <= tiles[l][0] + carpetLen - 1) {
        ans = Math.max(ans, tmp + carpetLen - tiles[r][0] + tiles[l][0])
      }
      tmp -= tiles[l][1] - tiles[l][0] + 1
      ++l
    }
  }
  return ans
}
