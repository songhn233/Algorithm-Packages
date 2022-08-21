const isPrefixOfWord = (sentence: string, searchWord: string) => {
  const v = sentence.split(' ').findIndex((v) => v.startsWith(searchWord))
  return v === -1 ? -1 : v + 1
}
