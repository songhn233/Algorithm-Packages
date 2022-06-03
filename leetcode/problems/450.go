func deleteNode(root *TreeNode, key int) *TreeNode {
  if root == nil {
    return nil
  }
  if key > root.Val {
    root.Right = deleteNode(root.Right, key)
  } else if key < root.Val {
    root.Left = deleteNode(root.Left, key)
  } else {
    if root.Left == nil {
      root = root.Right
    } else if root.Right == nil {
      root = root.Left
    } else {
      cur := root.Right
      for cur.Left != nil {
        cur = cur.Left
      }
      cur.Left = root.Left
      root = root.Right
    }
  }
  return root
}