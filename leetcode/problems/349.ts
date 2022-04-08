function intersection(nums1: number[], nums2: number[]): number[] {
  const set = new Set(nums1),
    ans = new Set<number>()
  nums2.forEach((v) => {
    if (set.has(v)) {
      ans.add(v)
    }
  })
  return [...ans.entries()].map((v) => v[0])
}
