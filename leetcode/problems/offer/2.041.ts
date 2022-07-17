class MovingAverage {
  arr: number[]
  size: number
  constructor(size: number) {
    this.arr = []
    this.size = size
  }

  next(val: number): number {
    while (this.arr.length >= this.size) this.arr.shift()
    this.arr.push(val)
    return this.arr.reduce((a, b) => a + b) / this.arr.length
  }
}
