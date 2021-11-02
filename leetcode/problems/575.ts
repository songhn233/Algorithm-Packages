function distributeCandies(candyType: number[]): number {
  const set = new Set()
  candyType.forEach((candy) => set.add(candy))
  return Math.min(set.size, candyType.length / 2)
}
