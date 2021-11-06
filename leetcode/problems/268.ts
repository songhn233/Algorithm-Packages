const missingNumber = (nums: number[]) =>
  (nums.length * (nums.length + 1)) / 2 - nums.reduce((sum, v) => sum + v)
