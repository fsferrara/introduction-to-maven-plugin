/*
With `const` the reference assigned to a variable is meant to be a constant one.
References assigned with Const cannot be changed. Note, we're saying references here and not values.
*/

// Scalar values
const answer = 42;
const greeting = 'Hello';

try {
    answer = 24;
} catch (error) {
    console.log("it's not possible to reassign a const number");
}

try {
    greeting = 'Hi';
} catch (error) {
    console.log("it's not possible to reassign a const string");
}


console.log('[Scalar Value] answer = ' + answer);
console.log('[Scalar Value] greeting = ' + greeting);
