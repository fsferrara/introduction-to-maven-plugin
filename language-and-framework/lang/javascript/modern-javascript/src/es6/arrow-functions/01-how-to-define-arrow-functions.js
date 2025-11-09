/*
There are many ways to define a function in JavaScript, and the modern specifications introduced a new way.
Arrow functions.
*/

const X = function() {
  console.log('[classic function] Hello!');
};

const Y = () =>   {
  console.log('[arrow function] Hello!');
};

X();
Y();
