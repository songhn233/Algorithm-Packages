function nextGreaterElement(n: number): number {
  const a = String(n).split('').map(Number),
    len = a.length
  let idx = -1
  for (let i = len - 2; i >= 0; i--) {
    for (let j = len - 1; j > i; j--) {
      if (a[i] < a[j]) {
        ;[a[i], a[j]] = [a[j], a[i]]
        idx = i
        break
      }
    }
    if (idx !== -1) break
  }
  if (idx === -1) {
    return -1
  }
  const tmp = a.slice(idx + 1)
  tmp.sort((a, b) => a - b)
  for (let i = idx + 1; i < len; i++) {
    a[i] = tmp[i - idx - 1]
  }
  const ans = Number(a.join(''))
  if (ans > Math.pow(2, 31) - 1) {
    return -1
  }
  return ans
}
