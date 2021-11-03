function isPerfectSquare(num: number): boolean {
  let l = 1,
    r = num
  while (l < r) {
    let mid = (l + r) >> 1
    if (mid * mid >= num) r = mid
    else l = mid + 1
  }
  return l * l === num
}
