/*
With `const` the reference assigned to a variable is meant to be a constant one.
References assigned with Const cannot be changed. Note, we're saying references here and not values.
*/

// Scalar values
const answer = 42;
const greeting = 'Hello';

console.log('[Scalar Value] answer = ' + answer);
console.log('[Scalar Value] greeting = ' + greeting);

// Arrays and Objects
const numbers = [2, 4, 6];
const person = {
  firstName: 'John',
  lastName: 'Doe',
}

console.log('[Array] numbers = ' + JSON.stringify(numbers));
console.log('[Objects] person = ' + JSON.stringify(person));
