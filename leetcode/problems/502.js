/**
 * @param {number} k
 * @param {number} w
 * @param {number[]} profits
 * @param {number[]} capital
 * @return {number}
 */
const findMaximizedCapital = (k, w, profits, capital) => {
  const p = new MaxPriorityQueue({
    priority: v => v.profits
  })
  const n = profits.length, arr = []

  for (let i = 0; i < n; i++) {
    arr.push({ profits: profits[i], capital: capital[i] })
  }

  arr.sort((a, b) => a.capital - b.capital)
  let idx = 0
  for (let i = 0; i < k; i++) {
    while (idx < n && arr[idx].capital <= w) {
      p.enqueue(arr[idx])
      idx++
    }

    if (p.isEmpty()) break

    w += p.dequeue().element.profits
  }
  return w
}