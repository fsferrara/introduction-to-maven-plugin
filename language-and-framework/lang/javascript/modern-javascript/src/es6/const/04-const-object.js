/*
With `const` the reference assigned to a variable is meant to be a constant one.
References assigned with Const cannot be changed. Note, we're saying references here and not values.
*/

// Object
const person = {
  firstName: 'John',
  lastName: 'Doe',
}

try {
    person = {
        firstName: 'Robinson',
        lastName: 'Crusoe',
    };
} catch (error) {
    console.log("it's not possible to reassign a const object");
}

// we can modify the array content
person.firstName = 'Eliza';

console.log('[Objects] person = ' + JSON.stringify(person));
