function dailyTemperatures(temperatures: number[]): number[] {
  const stack: number[] = []
  const ans = Array(temperatures.length).fill(0)
  let top = -1
  for (let i = 0; i < temperatures.length; i++) {
    while (top >= 0 && temperatures[stack[top]] < temperatures[i]) {
      ans[stack[top]] = i - stack[top]
      top -= 1
    }
    stack[++top] = i
  }
  return ans
}
