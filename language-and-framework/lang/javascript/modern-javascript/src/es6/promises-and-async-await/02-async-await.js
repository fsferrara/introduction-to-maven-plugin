/*
Async/Await is just a way to consumt Promises with cleaner code.
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

const handleStart = async () => {
  try {
    await start();
    console.log('OK');
  } catch (error) {
    console.log('KO');
  }
};

handleStart();
