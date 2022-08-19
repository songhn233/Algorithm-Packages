function constructMaximumBinaryTree(nums: number[]): TreeNode | null {
  if (nums.length <= 0) {
    return null
  }
  const idx = findMaxIdx(nums)
  const root = new TreeNode(nums[idx])
  root.left = constructMaximumBinaryTree(nums.slice(0, idx))
  root.right = constructMaximumBinaryTree(nums.slice(idx + 1))
  return root
}

function findMaxIdx(nums: number[]) {
  let idx = 0,
    val = nums[0]
  nums.forEach((v, i) => {
    if (v > val) {
      val = v
      idx = i
    }
  })
  return idx
}
