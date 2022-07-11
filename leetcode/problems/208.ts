class TrieNode {
  children: (TrieNode | null)[]
  end: boolean = false
  constructor() {
    this.children = Array(26).fill(null)
  }
}

class Trie {
  root: TrieNode
  constructor() {
    this.root = new TrieNode()
  }
  insert(words: string): void {
    let cur = this.root
    for (let word of words) {
      const idx = word.charCodeAt(0) - 'a'.charCodeAt(0)
      if (cur.children[idx] === null) {
        cur.children[idx] = new TrieNode()
      }
      cur = cur.children[idx]
    }
    cur.end = true
  }
  search(words: string) {
    let cur = this.root
    for (let word of words) {
      const idx = word.charCodeAt(0) - 'a'.charCodeAt(0)
      if (cur.children[idx]) {
        cur = cur.children[idx]
      } else {
        return false
      }
    }
    return cur.end
  }
  startsWith(prefix: string) {
    let cur = this.root
    for (let word of prefix) {
      const idx = word.charCodeAt(0) - 'a'.charCodeAt(0)
      if (cur.children[idx]) {
        cur = cur.children[idx]
      } else {
        return false
      }
    }
    return true
  }
}

/**
 * Your Trie object will be instantiated and called as such:
 * var obj = new Trie()
 * obj.insert(word)
 * var param_2 = obj.search(word)
 * var param_3 = obj.startsWith(prefix)
 */
