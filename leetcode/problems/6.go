func convert(s string, numRows int) string {
  if numRows < 2 {
    return s
  }
  arr := make([]string, numRows)
  i, flag := 0, - 1
  for _, v := range s {
    arr[i] += string(v)
    if i == 0 || i == numRows - 1 {
      flag = - flag
    }
    i += flag
  }
  return strings.Join(arr, "")
}