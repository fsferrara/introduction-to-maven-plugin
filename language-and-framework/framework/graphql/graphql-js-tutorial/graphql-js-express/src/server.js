var express = require('express');
var { graphqlHTTP } = require('express-graphql');
var { buildSchema } = require('graphql');

// Construct a schema
var schema = buildSchema(`
    type Query {
        hello: String
    }
`);

// Root with resolvers
var root = {
    hello: () => {
        return 'Hello gql express :-S';
    },
}

var app = express();

/**
 * graphqlHTTP({
 *   schema: GraphQLSchema,
 *   graphiql?: ?boolean,
 *   rootValue?: ?any,
 *   context?: ?any,
 *   pretty?: ?boolean,
 *   formatError?: ?Function,
 *   validationRules?: ?Array<any>,
 * }): Middleware
 */
app.use('/graphql', graphqlHTTP({
    schema,
    rootValue: root,
    graphiql: true,
}));

app.listen(4000);

console.log('🚀 http://localhost:4000/graphql');
