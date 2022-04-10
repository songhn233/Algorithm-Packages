function reverseStr(s: string, k: number): string {
  const arr = s.split('')
  const n = arr.length
  const reverse = (i: number, j: number) => {
    let l = i - 1,
      r = j + 1
    while (++l < --r) {
      ;[arr[l], arr[r]] = [arr[r], arr[l]]
    }
  }
  for (let i = 0; i < n; i += 2 * k) {
    if (i + k - 1 > n - 1) {
      reverse(i, n - 1)
    } else {
      reverse(i, i + k - 1)
    }
  }
  return arr.join('')
}
