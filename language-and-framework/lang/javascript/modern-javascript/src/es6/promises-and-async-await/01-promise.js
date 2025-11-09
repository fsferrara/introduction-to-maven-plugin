/*
Promises.
*/

function start() {
  return new Promise(function(resolve, reject) {
    console.log('...doing async stuff...');
    if (Math.random().toFixed(0) % 2 == 0) {
      resolve();
    } else {
      reject();
    }
  });
}

start().then(function() {console.log('OK')}, function() {console.log('KO')});
