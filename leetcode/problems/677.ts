class Trie {
  val: number
  next: any[]
  constructor() {
    this.val = 0
    this.next = Array(26).fill(0)
  }
}
class MapSum {
  trie: Trie
  map: Map<string, number>
  constructor() {
    this.trie = new Trie()
    this.map = new Map()
  }

  insert(key: string, val: number): void {
    const ins = val - (this.map.has(key) ? this.map.get(key) : 0)
    this.map.set(key, val)
    let node = this.trie
    for (let x of key) {
      if (!node.next[x]) {
        node.next[x] = new Trie()
      }
      node = node.next[x]
      node.val += ins
    }
  }

  sum(prefix: string): number {
    let node = this.trie
    for (let x of prefix) {
      if (!node.next[x]) {
        return 0
      }
      node = node.next[x]
    }
    return node.val
  }
}
