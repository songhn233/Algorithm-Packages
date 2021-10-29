const singleNumber = (nums: number[]) => {
  const xor = nums.reduce((c, v) => c ^ v, 0)
  const t = xor & -xor
  return nums.reduce(([a, b], v) => (v & t ? [a ^ v, b] : [a, b ^ v]), [0, 0])
}
