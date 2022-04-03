class MyLinkedList {
  list: ListNode | null
  size: number
  constructor() {
    this.list = new ListNode()
    this.size = 0
  }
  get(index: number): number {
    let p = this.list
    if (index >= this.size) {
      return -1
    } else {
      while (index >= 0) {
        p = p.next
        --index
      }
      return p.val
    }
  }
  addAtHead(val: number): void {
    const q = new ListNode(val)
    const p = this.list
    q.next = p.next
    p.next = q
    ++this.size
  }
  addAtTail(val: number): void {
    let p = this.list
    while (p.next) {
      p = p.next
    }
    p.next = new ListNode(val)
    ++this.size
  }
  addAtIndex(index: number, val: number): void {
    if (index < 0) {
      this.addAtHead(val)
    } else if (this.size === index) {
      let p = this.list
      while (p.next) {
        p = p.next
      }
      p.next = new ListNode(val)
      ++this.size
    } else if (index < this.size) {
      let cur = this.list,
        pre = new ListNode()
      while (index >= 0) {
        pre = cur
        cur = cur.next
        --index
      }
      const q = new ListNode(val)
      q.next = pre.next
      pre.next = q
      ++this.size
    }
  }
  deleteAtIndex(index: number): void {
    let p = this.list
    let pre = new ListNode()
    if (index >= this.size) {
      return
    } else {
      while (index >= 0) {
        pre = p
        p = p.next
        --index
      }
      pre.next = p.next
      --this.size
    }
  }
}
