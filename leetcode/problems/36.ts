function isValidSudoku(board: string[][]): boolean {
  const rows = Array(10)
    .fill(0)
    .map((_) => Array(10).fill(0))
  const cols = Array(10)
    .fill(0)
    .map((_) => Array(10).fill(0))
  const block = Array(3)
    .fill(0)
    .map((_) =>
      Array(3)
        .fill(0)
        .map((_) => Array(9).fill(0))
    )
  const n = board.length
  for (let i = 0; i < n; i++) {
    const m = board[i].length
    for (let j = 0; j < m; j++) {
      const ele = Number(board[i][j]) - 1
      ;(rows[i][ele] += 1), (cols[j][ele] += 1)
      const x = Math.floor(i / 3),
        y = Math.floor(j / 3)
      block[x][y][ele] += 1
      if (rows[i][ele] > 1 || cols[j][ele] > 1 || block[x][y][ele] > 1) {
        return false
      }
    }
  }
  return true
}
