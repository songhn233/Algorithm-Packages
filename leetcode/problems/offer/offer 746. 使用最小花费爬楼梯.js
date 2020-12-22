/**
 * @param {number[]} cost
 * @return {number}
 */
const minCostClimbingStairs = (cost) => {
  const f = new Array(cost.length + 1).fill(0)
  for (let i = 2; i <= cost.length; i++) {
    f[i] = Math.min(f[i - 1] + cost[i - 1], f[i - 2] + cost[i - 2])
  }
  console.log(f)
  return f[cost.length]
}
