const singleNumber = (nums: number[]) => nums.reduce((a, v) => a ^ v, 0)
