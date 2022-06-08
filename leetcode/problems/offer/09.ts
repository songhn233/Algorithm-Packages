class CQueue {
  in: number[]
  out: number[]
  constructor() {
    this.in = []
    this.out = []
  }
  appendTail(value: number): void {
    this.in.push(value)
  }
  deleteHead(): number {
    if (this.out.length) {
      return this.out.pop()
    } else {
      while (this.in.length) {
        this.out.push(this.in.pop())
      }
      return this.out.length ? this.out.pop() : -1
    }
  }
}
