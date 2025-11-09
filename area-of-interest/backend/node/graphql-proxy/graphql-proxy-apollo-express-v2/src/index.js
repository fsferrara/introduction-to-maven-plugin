const server = require('./server');

const run = function() {
    server.start({
        port: 8001,
        uri: 'https://graphql-weather-api.herokuapp.com/',
        headers: {},
    })
}

run();
