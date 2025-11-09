/*
We can select a bunch of field with the rest operator `...`
*/

const data = {
    foo: 'bar',
    firstName: 'John',
    lastName: 'Doe',
};

const {foo, ...otherFields} = data;
console.log('foo = ' + foo);
console.log('otherFields = ' + JSON.stringify(otherFields));

const person = {
    ...otherFields
};

console.log(person);
