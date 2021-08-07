/**
 * @param {number[][]} intervals
 * @return {number[][]}
 */
const merge = a =>
  a
    .slice()
    .sort((x, y) => x[0] - y[0])
    .reduce((acc, v) => {
      if (!acc.length || acc[acc.length - 1][1] < v[0]) {
        acc.push(v);
      } else {
        acc[acc.length - 1][1] = Math.max(acc[acc.length - 1][1], v[1]);
      }
      return acc;
    }, []);