var { graphql, buildSchema } = require('graphql');

class GqlEngine {

    constructor() {
        // Construct a schema
        this.schema = buildSchema(`
            type Query {
                hello: String
            }
        `);

        // The root provides a resolver for each API endipoint
        this.root = {
            hello: () => {
                return 'Hello graphql!';
            },
        };
    }

    execute(query) {
        // Run the GraphQL query '{ hello }' and print out the response
        graphql(this.schema, query, this.root).then( (response) => {
            console.log(JSON.stringify(response));
        });
    }
}

module.exports = GqlEngine;
