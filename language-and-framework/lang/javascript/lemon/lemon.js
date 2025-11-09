var prompt = require('prompt');

prompt.start();

prompt.get(['fruit'], function(err, result) {

	if (result) {
		console.log('Hey fruit ' + result.fruit + '.');
		if ('lemon' == result.fruit) {
			console.log('I like yellow things :) ');
		};
                if ('mandarin' == result.fruit) {
                        console.log('Honestly I like all the citrus fruits');
                };
                if ('orange' == result.fruit) {
                        console.log('Honestly I like all the citrus fruits');
                };
	}
});
