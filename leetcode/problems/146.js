/**
 * @param {number} capacity
 */
var LRUCache = function (capacity) {
  this.map = new Map()
  this.cap = capacity
  this.size = 0
}

/**
 * @param {number} key
 * @return {number}
 */
LRUCache.prototype.get = function (key) {
  if (!this.map.has(key)) {
    return -1
  }
  const v = this.map.get(key)
  this.map.delete(key)
  this.map.set(key, v)
  return v
}

/**
 * @param {number} key
 * @param {number} value
 * @return {void}
 */
LRUCache.prototype.put = function (key, value) {
  if (!this.map.has(key)) {
    const keys = this.map.keys()
    while (this.size + 1 > this.cap) {
      const key = keys.next().value
      this.map.delete(key)
      this.size--
    }
    this.map.set(key, value)
    this.size++
  } else {
    this.map.delete(key)
    this.map.set(key, value)
  }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * var obj = new LRUCache(capacity)
 * var param_1 = obj.get(key)
 * obj.put(key,value)
 */
