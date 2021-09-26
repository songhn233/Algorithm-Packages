interface Node {
  val: number
  prev: Node | null
  next: Node | null
  child: Node | null
}

function flatten(head: Node | null): Node | null {
  const dfs = (head: Node | null) => {
    let cur = head,
      next = null,
      last = null
    while (cur) {
      next = cur.next
      if (cur.child) {
        last = dfs(cur.child)
        cur.next = cur.child
        cur.child.prev = cur
        cur.child = null
        if (next) {
          last.next = next
          next.prev = last
        }
      } else {
        last = cur
      }
      cur = next
    }
    return last
  }
  dfs(head)
  return head
}
