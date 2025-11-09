const { ApolloServer, gql } = require('apollo-server');
const { buildFederatedSchema } = require('@apollo/federation');

const typeDefs = gql`
    type Query {
        review: Review
    }

    type Review {
        product: Product,
        stars: Int!
        text: String
    }

    # This is a "stub" of the Product entity
    # Because the Product entity is defined in another service, the reviews service needs
    # to define a stub of it to make its own schema valid. The stub includes just enough
    # information for the service to know how to interact with a Product.
    extend type Product @key(fields: "upc") {
        upc: String! @external # @external directive to indicate that the field originates in another service
    }
`;

const resolvers = {
    Query: {
        review() {
            return {
                upc: "1",
                stars: 5,
                text: "Great experience with it. Absolutely recommended!"
            }
        }
    },
    Review: {
        product(review) {
            // The reviews service needs to define its own resolver for the Product entity.
            // The reviews service doesn't know much about Products, but fortunately, it doesn't
            // need to. All it needs to do is return enough information to uniquely identify
            // a given Product, like so:
            return { __typename: "Product", upc: review.upc };
        }
    }
};

const server = new ApolloServer ({
    schema: buildFederatedSchema([{ typeDefs, resolvers}])
});

server.listen(4002).then(({ url }) => {
    console.log(`🚀 Server ready at ${url}`);
});
