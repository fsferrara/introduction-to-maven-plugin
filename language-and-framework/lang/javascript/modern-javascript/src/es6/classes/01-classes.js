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

const o1 = new Person('John');
o1.greet();
