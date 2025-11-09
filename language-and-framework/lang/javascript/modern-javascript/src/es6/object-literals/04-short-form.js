/*
With ES6 we can the following shorthand.
*/

const inverseOfPi = 1 / Math.PI;

const obj = {
  inverseOfPi // this is equivalent to `inverseOfPi: inverseOfPi`
};

console.log(JSON.stringify(obj));
