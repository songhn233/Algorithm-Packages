/**
 * @param {number[]} A
 * @param {number[]} B
 * @param {number[]} C
 * @param {number[]} D
 * @return {number}
 */
const fourSumCount = (A, B, C, D) => {
  const map = new Map()
  let ans = 0
  for (let i = 0; i < A.length; i++) {
    for (let j = 0; j < B.length; j++) {
      map.set(
        -A[i] - B[j],
        (map.has(-A[i] - B[j]) ? map.get(-A[i] - B[j]) : 0) + 1
      )
    }
  }
  for (let i = 0; i < C.length; i++) {
    for (let j = 0; j < D.length; j++) {
      if (map.has(C[i] + D[j])) {
        ans += map.get(C[i] + D[j])
      }
    }
  }
  return ans
}
