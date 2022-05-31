function merge(A: number[], m: number, B: number[], n: number): void {
  let i = m - 1,
    j = n - 1,
    t = n + m - 1
  while (i >= 0 && j >= 0) {
    if (A[i] > B[j]) {
      A[t--] = A[i--]
    } else {
      A[t--] = B[j--]
    }
  }
  while (i >= 0) A[t--] = A[i--]
  while (j >= 0) A[t--] = B[j--]
}
