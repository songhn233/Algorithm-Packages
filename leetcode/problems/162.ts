const findPeakElement = (nums: number[]) =>
  nums.reduce((maxx, v, idx) => (v > nums[maxx] ? idx : maxx), 0)
