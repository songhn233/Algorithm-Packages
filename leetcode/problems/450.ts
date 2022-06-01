function deleteNode(root: TreeNode | null, key: number): TreeNode | null {
  if (!root) {
    return root
  }
  if (key > root.val) root.right = deleteNode(root.right, key)
  else if (key < root.val) root.left = deleteNode(root.left, key)
  else {
    if (!root.left) root = root.right
    else if (!root.right) root = root.left
    else {
      let t = root.right
      while (t.left) {
        t = t.left
      }
      t.left = root.left
      root = root.right
    }
  }
  return root
}
