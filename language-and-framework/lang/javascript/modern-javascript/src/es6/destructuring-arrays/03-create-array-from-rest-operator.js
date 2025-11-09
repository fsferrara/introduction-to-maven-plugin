/*
Destructuring an array using the rest operator `...`
Very useful to split an array 
*/

const [first, ...resfOfItems] = [10, 20, 30, 40]

console.log('first item = ' + first);
console.log('rest of items = ' + resfOfItems);

const newArray = [...resfOfItems];
console.log('new array created from ...resfOfItems = ' + newArray);
