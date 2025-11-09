const fetch = require('node-fetch');
const { ApolloServer } = require('apollo-server-express');

const {setContext} = require('apollo-link-context');
const {HttpLink} = require('apollo-link-http');

const express = require('express');
const { introspectSchema, makeRemoteExecutableSchema, mergeSchemas } = require('graphql-tools');

async function start({
    port,
    uri,
    headers
}) {
    const httpLink = new HttpLink({
        uri,
        fetch,
    });

    const link = setContext((request, previousContext) => ({
        headers,
    })).concat(httpLink);

    const schema = await introspectSchema(link);

    const executableSchema = makeRemoteExecutableSchema({
        schema,
        link,
    });

    const mergedSchema = mergeSchemas({
        schemas: [executableSchema]
    });

    const app = express();

    const server = new ApolloServer({
        schema: mergedSchema
    });
    server.applyMiddleware({ app });

    app.listen({port});
    console.log(`🚀 Server ready at http://localhost:${port}/graphql and connect to ${uri}`);

    return app;
}

module.exports = {
    start
}
