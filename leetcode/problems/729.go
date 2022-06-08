type Pair struct {
  start, end int
}
type MyCalendar struct {
  arr []Pair
}


func Constructor() MyCalendar {
  return MyCalendar{[]Pair{}}
}


func (this *MyCalendar) Book(start int, end int) bool {
  for _, v := range this.arr {
    if v.end <= start || v.start >= end {
      continue
    }
    return false
  }
  this.arr = append(this.arr, Pair{start, end})
  return true
}
