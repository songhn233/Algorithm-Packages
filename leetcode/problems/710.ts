class Solution {
  map = new Map<number, number>()
  set = new Set<number>()
  lim: number
  constructor(n: number, blacklist: number[]) {
    this.lim = n - blacklist.length
    for (let v of blacklist) {
      if (v >= this.lim) {
        this.set.add(v)
      }
    }
    let tar = this.lim
    for (let v of blacklist) {
      if (v < this.lim) {
        while (this.set.has(tar)) {
          ++tar
        }
        this.map.set(v, tar)
        ++tar
      }
    }
  }

  pick(): number {
    const v = Math.floor(Math.random() * this.lim)
    return this.map.get(v) || v
  }
}
