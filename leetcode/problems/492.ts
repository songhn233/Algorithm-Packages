function constructRectangle(area: number): number[] {
  let t = Math.floor(Math.sqrt(area))
  while (area % t) {
    t--
  }
  return [area / t, t]
}
