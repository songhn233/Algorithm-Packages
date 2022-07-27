class Solution {
  origin: number[]
  nums: number[]
  constructor(nums: number[]) {
    this.origin = nums.slice()
    this.nums = nums
  }

  reset(): number[] {
    this.nums = this.origin.slice()
    return this.nums
  }

  shuffle(): number[] {
    const n = this.nums.length
    for (let i = 0; i < n; i++) {
      const idx = Math.floor(Math.random() * (n - i))
      ;[this.nums[n - i - 1], this.nums[idx]] = [
        this.nums[idx],
        this.nums[n - i - 1],
      ]
    }
    return this.nums
  }
}

/**
 * Your Solution object will be instantiated and called as such:
 * var obj = new Solution(nums)
 * var param_1 = obj.reset()
 * var param_2 = obj.shuffle()
 */
