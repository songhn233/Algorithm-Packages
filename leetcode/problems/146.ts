class List {
  val: number
  key: number
  next: List | null
  pre: List | null
  constructor(key?: number, value?: number) {
    this.key = key
    this.val = value
  }
}
class LRUCache {
  head: List
  tail: List
  map: Map<number, List>
  len: number
  cap: number
  constructor(capacity: number) {
    this.map = new Map()
    this.head = new List()
    this.tail = new List()
    this.head.next = this.tail
    this.tail.pre = this.head
    this.len = 0
    this.cap = capacity
  }
  get(key: number): number {
    if (this.map.has(key)) {
      const target = this.map.get(key)
      const ins = new List(target.key, target.val)
      this._remove(target)
      this._addHead(ins)
      this.map.set(key, ins)
      return ins.val
    } else {
      return -1
    }
  }

  put(key: number, value: number): void {
    if (this.map.has(key)) {
      const target = this.map.get(key)
      const ins = new List(target.key, value)
      this._remove(target)
      this._addHead(ins)
      this.map.set(key, ins)
    } else {
      const p = new List(key, value)
      this._addHead(p)
      this.len++
      this.map.set(key, p)
      if (this.len > this.cap) {
        this.map.delete(this.tail.pre.key)
        this._remove(this.tail.pre)
        this.len--
      }
    }
  }
  _addHead(p: List) {
    p.pre = this.head
    p.next = this.head.next
    p.next.pre = p
    this.head.next = p
  }
  _remove(p: List) {
    const x = p.next
    p.pre.next = x
    x.pre = p.pre
  }
}
