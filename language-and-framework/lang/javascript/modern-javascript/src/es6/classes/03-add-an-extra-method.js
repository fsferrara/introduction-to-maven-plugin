/*
Javascript offers many programming paradigms. And object oriented programming is one of them.
Everything in JavaScript is an object, including functions.
Modern Java script also added support for classes.
A class is a template or blueprint for you to define shared structure and behavior between similar objects.
*/

class Person {
  constructor(name) {
    this.name = name;
  }
  greet() {
    console.log(`Hello ${this.name}`);
  }
}

const o3 = new Person('Alice');
o3.goodbye = function() {console.log('Goodbye!')};

o3.greet();
o3.goodbye();
