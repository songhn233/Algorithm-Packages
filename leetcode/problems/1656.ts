class OrderedStream {
  array: string[]
  ptr: number = 1
  constructor(n: number) {
    this.array = Array(n + 1).fill('')
  }
  insert(idKey: number, value: string): string[] {
    this.array[idKey] = value
    const ans: string[] = []
    if (this.ptr === idKey) {
      while (this.array[this.ptr]) {
        ans.push(this.array[this.ptr])
        this.ptr++
      }
    }
    return ans
  }
}
