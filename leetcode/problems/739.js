/**
 * @param {number[]} temperatures
 * @return {number[]}
 */
const dailyTemperatures = function (temperatures) {
  const sta = [],
    n = temperatures.length
  const ans = Array(n).fill(0)
  let top = -1
  for (let i = 0; i < n; i++) {
    while (top >= 0 && temperatures[sta[top]] < temperatures[i]) {
      ans[sta[top]] = i - sta[top]
      --top
    }
    sta[++top] = i
  }
  return ans
}
