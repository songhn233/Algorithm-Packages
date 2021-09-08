function smallestK(arr: number[], k: number): number[] {
  arr.sort((a, b) => a - b)
  return arr.slice(0, k)
}
