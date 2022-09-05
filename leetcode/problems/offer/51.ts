function reversePairs(nums: number[]): number {
  return sortCount(nums, 0, nums.length - 1)
}

function sortCount(arr: number[], l: number, r: number): number {
  if (l >= r) {
    return 0
  }
  let mid = (l + r) >> 1,
    i = l,
    j = mid + 1
  let ans = sortCount(arr, l, mid) + sortCount(arr, mid + 1, r)
  const tmp: number[] = []
  while (i <= mid && j <= r) {
    if (arr[i] <= arr[j]) {
      tmp.push(arr[i])
      i++
      ans += j - mid - 1
    } else {
      tmp.push(arr[j])
      j++
    }
  }
  while (i <= mid) {
    tmp.push(arr[i])
    i++
    ans += j - mid - 1
  }
  while (j <= r) {
    tmp.push(arr[j])
    j++
  }
  for (let i = l; i <= r; i++) arr[i] = tmp[i - l]
  return ans
}
