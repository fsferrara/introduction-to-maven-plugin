// When is javascript running?
setInterval(() => {
  for (var n = 0; n < 1e9; n++) {}
  console.log('test');
}, 500);

