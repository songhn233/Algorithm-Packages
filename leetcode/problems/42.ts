const max = (x: number, y: number) => (x > y ? x : y)
const min = (x: number, y: number) => (x < y ? x : y)
function trap(height: number[]): number {
  const n = height.length
  let l = Array(n).fill(0),
    r = Array(n).fill(0)
  let ans = 0
  ;(l[0] = height[0]), (r[n - 1] = height[n - 1])
  for (let i = 1; i < n; i++) {
    l[i] = max(l[i - 1], height[i])
  }
  for (let i = n - 2; i >= 0; i--) {
    r[i] = max(height[i], r[i + 1])
  }
  for (let i = 0; i < n; i++) {
    ans += min(l[i], r[i]) - height[i]
  }
  return ans
}
