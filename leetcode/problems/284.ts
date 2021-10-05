/**
 * // This is the Iterator's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Iterator {
 *      hasNext(): boolean {}
 *
 *      next(): number {}
 * }
 */

class PeekingIterator {
  iterator: Iterator
  private nextElement: number | null
  constructor(iterator: Iterator) {
    this.iterator = iterator
    this.nextElement = this.iterator.next()
  }

  peek(): number {
    return this.nextElement
  }

  next(): number {
    const tmp = this.nextElement
    this.nextElement = this.iterator.hasNext() ? this.iterator.next() : null
    return tmp
  }

  hasNext(): boolean {
    return !!this.nextElement
  }
}
