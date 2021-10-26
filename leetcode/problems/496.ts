function nextGreaterElement(nums1: number[], nums2: number[]): number[] {
  const map = new Map(),
    sta = []
  let top = 0
  const ans = Array(nums2.length).fill(-1)
  for (let [idx, v] of nums2.entries()) {
    map.set(v, idx)
    while (top && nums2[sta[top - 1]] < v) {
      ans[sta[top - 1]] = v
      top--
    }
    sta[top++] = idx
  }
  return nums1.reduce((arr, v) => [...arr, ans[map.get(v)]], [])
}
