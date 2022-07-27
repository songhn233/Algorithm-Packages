function arrayRankTransform(arr: number[]): number[] {
  const target = [...new Set(arr.slice())]
  target.sort((a, b) => a - b)
  return arr.map((v) => target.indexOf(v) + 1)
}
