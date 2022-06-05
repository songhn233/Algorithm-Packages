type Solution struct {
  radius, x_center, y_center float64
}

func Constructor(radius float64, x_center float64, y_center float64) Solution {
  return Solution{radius, x_center, y_center}
}

func (this *Solution) RandPoint() []float64 {
  len, theta := math.Sqrt(rand.Float64() * this.radius * this.radius), rand.Float64() * math.Pi * 2
  return []float64{this.x_center + len * math.Cos(theta), this.y_center + len * math.Sin(theta)}
}
