/*
A regular function binds the value of `this` keyword to the value of its `this` caller.
*/

const testerObject = {
  name: 'tester object environment',
  x: function() {
    console.log('[x()] this = ' + JSON.stringify(this));
  }
};

this.name = 'calling enviroment';
console.log('[calling environment] this = ' + JSON.stringify(this));

testerObject.x();
