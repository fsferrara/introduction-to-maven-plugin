const { ApolloServer } = require('apollo-server');
const { ApolloGateway } = require('@apollo/gateway');
const contextPlugin = require('./contextPlugin');
const ContextDataSource = require('./ContextDataSource');


// Initialize an ApolloGateway instance and pass it an array of
// your implementing service names and URLs
const gateway = new ApolloGateway({
    serviceList: [
        { name: 'products', url: 'http://products:4001' },
        { name: 'reviews', url: 'http://reviews:4002' },
    ],
    buildService({ name, url }) {
        return new ContextDataSource({ url });
    },
});

// Pass the ApolloGateway to the ApolloServer constructor
const server = new ApolloServer({
    gateway,
    subscriptions: false, // Disable subscriptions (not currently supported with ApolloGateway)
    context: () => {
        return ({
            headersToForward: []
        })
    },
    plugins: [
        contextPlugin({ }),
    ]
});

server.listen().then(({ url }) => {
    console.log(`🚀 Gateway ready at ${url}`);
});
