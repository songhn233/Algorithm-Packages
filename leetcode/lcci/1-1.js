/**
 * @param {string} astr
 * @return {boolean}
 */
const isUnique = (astr) => {
  return new Set(astr).size === astr.length;
};
