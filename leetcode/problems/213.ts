const rob = (nums: number[]) => {
  const n = nums.length
  if (n === 0 || n === 1) {
    return nums[0] ?? 0
  } else if (n === 2) {
    return Math.max(...nums)
  } else {
    return Math.max(subRob(nums, 0, n - 2), subRob(nums, 1, n - 1))
  }
}

const subRob = (nums: number[], l: number, r: number) => {
  const n = r - l + 1
  if (n === 1) {
    return nums[l]
  } else if (n === 2) {
    return Math.max(nums[l], nums[l + 1])
  } else {
    const f = Array(n).fill(0)
    ;(f[0] = nums[l]), (f[1] = Math.max(nums[l], nums[l + 1]))
    const arr = nums.slice(l, r + 1)
    for (let i = 2; i < arr.length; i++) {
      f[i] = Math.max(f[i - 2] + arr[i], f[i - 1])
    }
    return f[arr.length - 1]
  }
}
