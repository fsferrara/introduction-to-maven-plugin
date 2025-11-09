const { ApolloServer, gql } = require('apollo-server');
const { buildFederatedSchema } = require('@apollo/federation');

const typeDefs = gql`
    type Query {
        product: Product
    }
    
    # The @key directive defines the entity's primary key
    type Product @key(fields: "upc") {
        upc: String!
        name: String!
        price: Int
    }
`;

const resolvers = {
    Query: {
        product() {
            console.log('[implementing-service][products][main-resolver] working!');
            return {
                upc: "1",
                name: "raspberry",
                price: 74
            }
        }
    },
    Product: {
        // The originating service (in this case, products) must define a reference resolver for
        // the Product entity. Reference resolvers are a special addition to Apollo Server that
        // enable entities to be referenced by other services.
        __resolveReference(reference) {
            console.log('[implementing-service][products][reference-resolver] working!');
            return {
                upc: reference.upc,
                name: "raspberry",
                price: 74
            };
        }
    }
};

const server = new ApolloServer ({
    schema: buildFederatedSchema([{ typeDefs, resolvers}])
});

server.listen(4001).then(({ url }) => {
    console.log(`🚀 Server ready at ${url}`);
});
