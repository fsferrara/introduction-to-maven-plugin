/*
With `const` the reference assigned to a variable is meant to be a constant one.
References assigned with Const cannot be changed. Note, we're saying references here and not values.
*/

// Array
const numbers = [2, 4, 6];

try {
    numbers = [8, 10, 12];
} catch (error) {
    console.log("it's not possible to reassign a const array");
}

// we can modify the array content
numbers.push(42);

console.log('[Array] numbers = ' + JSON.stringify(numbers));
