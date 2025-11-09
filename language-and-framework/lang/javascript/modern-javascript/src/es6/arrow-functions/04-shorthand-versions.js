/*
There are many ways to define a function in JavaScript, and the modern specifications introduced a new way.
Arrow functions.
*/

// full version
const add = (a, b) =>   {
  const sum = a + b;
  console.log('sum = ' + sum);
};
add(2,4);

// shorthand version in case of single linve function
const singleLineAdd = (a, b) => console.log('sum = ' + (a+b));
singleLineAdd(3, 6);

// shorthand version in case of exactly one argument
const incrementSingleArgument = acc => console.log('acc = ' + ++acc);
incrementSingleArgument(1);
