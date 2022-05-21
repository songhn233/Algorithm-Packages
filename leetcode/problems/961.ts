const repeatedNTimes = (nums: number[]) => {
  const set = new Set()
  for (let v of nums) {
    if (set.has(v)) {
      return v
    }
    set.add(v)
  }
}
