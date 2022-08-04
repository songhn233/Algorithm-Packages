function trap(height) {
  const n = height.length,
    l = Array(n).fill(0),
    r = Array(n).fill(0)
  l[0] = height[0]
  for (let i = 1; i < n; i++) {
    l[i] = Math.max(l[i - 1], height[i])
  }
  r[n - 1] = height[n - 1]
  for (let i = n - 2; i >= 0; i--) {
    r[i] = Math.max(r[i + 1], height[i])
  }
  let ans = 0
  for (let i = 0; i < n; i++) {
    ans += Math.min(l[i], r[i]) - height[i]
  }
  return ans
}
