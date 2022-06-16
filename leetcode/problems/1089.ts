function duplicateZeros(arr: number[]): void {
  const t = []
  for (let v of arr) {
    if (t.length >= arr.length) {
      break
    }
    if (v !== 0) {
      t.push(v)
      continue
    }
    t.push(0, 0)
  }
  for (let i = 0; i < arr.length; i++) {
    arr[i] = t[i]
  }
}
