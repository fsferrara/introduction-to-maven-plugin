const fetch = require('node-fetch');
const {
    introspectSchema,
    makeRemoteExecutableSchema,
    ApolloServer,
} = require('apollo-server');
const {setContext} = require('apollo-link-context');
const {HttpLink} = require('apollo-link-http');

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

    const server = new ApolloServer({
        schema: executableSchema,
        port
    });

    try {
        await server.listen(port);
        console.log(`🚀 Server ready at http://localhost:${port}/ and connect to ${uri}`);
        return server;
    } catch (e) {
        console.log(e);
    }
}

module.exports = {
    start
}
