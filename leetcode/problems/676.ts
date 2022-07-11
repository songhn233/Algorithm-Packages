class MagicDictionary {
  arr: string[]
  constructor() {
    this.arr = []
  }
  buildDict(dictionary: string[]): void {
    this.arr = [...dictionary]
  }
  search(searchWord: string): boolean {
    let flag = false
    for (let str of this.arr) {
      if (str.length !== searchWord.length) {
        continue
      }
      let diff = 0
      for (let [i, char] of str.split('').entries()) {
        if (char !== searchWord[i]) {
          ++diff
        }
      }
      if (diff === 1) {
        flag = true
        break
      }
    }
    return flag
  }
}

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * var obj = new MagicDictionary()
 * obj.buildDict(dictionary)
 * var param_2 = obj.search(searchWord)
 */
