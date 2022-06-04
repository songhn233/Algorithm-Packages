func numUniqueEmails(emails []string) int {
  set := map[string]bool{}
  for _, v := range emails {
    arr := strings.Split(v, "@")
    pre, suf := arr[0], arr[1]
    pre = strings.ReplaceAll(strings.Split(pre, "+")[0], ".", "")
    set[pre + "@" + suf] = true
  }
  return len(set)
}