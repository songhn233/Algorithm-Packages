function successfulPairs(
  spells: number[],
  potions: number[],
  success: number
): number[] {
  const n = spells.length,
    m = potions.length
  const ans = []
  potions.sort((a, b) => a - b)
  for (let i = 0; i < n; i++) {
    const v = spells[i]
    let l = 0,
      r = m - 1
    while (l < r) {
      const m = (l + r) >> 1
      if (v * potions[m] >= success) r = m
      else l = m + 1
    }
    if (v * potions[l] >= success) {
      ans.push(m - l)
    } else {
      ans.push(0)
    }
  }
  return ans
}
