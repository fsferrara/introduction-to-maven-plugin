/*
With ES6 we can include arrow functions in object literals.
*/

const obj = {
  f1: (a, b) => {
    const sum = a + b;
    console.log('sum = ' + sum);
  },
  f2: (a, b) => console.log('sum = ' + (a+b)),
  f3: inc => inc++
};
