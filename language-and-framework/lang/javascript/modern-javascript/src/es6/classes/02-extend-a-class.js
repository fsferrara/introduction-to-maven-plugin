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

class Student extends Person {
  constructor(name, level) {
    super(name);
    this.level = level;
  }
  greet() {
    console.log(`Hello ${this.name} from ${this.level}`);
  }
}

const o2 = new Student('Max', '1st Grade');
o2.greet();
