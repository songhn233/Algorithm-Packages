func work(l chan int, quit chan bool, wg *sync.WaitGroup) {
  x, y := 0, 1
  for {
    select {
      case l <- x:
        x, y = y, x + y
      case <- quit:
        wg.Done()
        return 
    }
  }
}

func fib(n int) int {
    l, quit := make(chan int), make(chan bool)
    v := 0
    var wg sync.WaitGroup
    wg.Add(2)
    go func() {
      for i := 0; i <= n; i ++ {
        v = <- l
      }
      quit <- true
      wg.Done()
    }()
    go work(l, quit, &wg)
    wg.Wait()
    return v
}