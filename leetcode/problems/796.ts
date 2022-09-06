const rotateString = (s: string, goal: string) =>
  s.length === goal.length && String(s + s).includes(goal)
