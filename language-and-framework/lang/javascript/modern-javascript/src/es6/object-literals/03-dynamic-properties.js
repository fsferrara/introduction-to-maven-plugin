/*
With ES6 we can use dynamic properties.
The syntax looks like an array, but it's not!
*/

const mystery = 'answer';

const obj = {
  [mystery]: 42
};

// Interview Question: what is the value of `obj.mystery`?

console.log(JSON.stringify(obj));
