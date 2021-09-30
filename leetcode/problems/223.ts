const max = (a: number, b: number) => (a > b ? a : b)
const min = (a: number, b: number) => (a < b ? a : b)

function computeArea(
  ax1: number,
  ay1: number,
  ax2: number,
  ay2: number,
  bx1: number,
  by1: number,
  bx2: number,
  by2: number
): number {
  const x = max(0, min(ax2, bx2) - max(ax1, bx1))
  const y = max(0, min(ay2, by2) - max(ay1, by1))
  return (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1) - x * y
}
