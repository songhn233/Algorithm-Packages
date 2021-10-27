function reorderedPowerOf2(n: number): boolean {
  const maxn = 1e9
  let base = 1
  const set = new Set()
  const calc = (base: number) => {
    const num = String(base)
    const tmp: number[] = Array(10).fill(0)
    num.split('').map((v) => ++tmp[v])
    const key = tmp.reduce((acc, v) => acc + String(v), '')
    return key
  }
  while (base <= maxn) {
    set.add(calc(base))
    base <<= 1
  }
  return set.has(calc(n)) ? true : false
}
