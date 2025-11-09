/*
An arrow function will close over the value of the `this` keyword for its scope at the time it was defined.
This makes it great for delayed execution cases like events and listeners because it gives easy access to the
defining environment, not the calling environment.
*/

const testerObject = {
  name: 'testerObject',
  y: () => {
    console.log('[y()] this = ' + JSON.stringify(this));
  }
};

this.name = 'calling enviroment';
console.log('[calling environment] this = ' + JSON.stringify(this));

testerObject.y();
