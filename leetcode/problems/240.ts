function searchMatrix(matrix: number[][], target: number): boolean {
  let n = matrix.length,
    m = matrix[0].length,
    i = 0,
    j = m - 1
  while (j >= 0 && i < n) {
    if (matrix[i][j] === target) return true
    else if (matrix[i][j] > target) j--
    else i++
  }
  return false
}
