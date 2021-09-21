Array.prototype.last = function () {
  return this[this.length - 1];
};
const lengthOfLastWord = (s) => s.split(' ').filter((x) => x.length).last().length;
