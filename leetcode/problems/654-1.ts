function constructMaximumBinaryTree(nums: number[]): TreeNode | null {
  const s = new Array<TreeNode>(nums.length)
  let top = -1
  for (const v of nums) {
    const node = new TreeNode(v)
    while (top >= 0 && s[top].val < v) node.left = s[top--]
    if (top >= 0) s[top].right = node
    s[++top] = node
  }
  return s[0]
}
