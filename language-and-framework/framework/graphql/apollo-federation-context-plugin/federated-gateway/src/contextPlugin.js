module.exports = (options) => {
    return {
        requestDidStart() {
            return {
                /**
                 * The didResolveOperation event fires after the graphql library successfully determines the operation
                 * to execute from a request's document AST.
                 * At this stage, both the operationName string and operation AST are available.
                 * This event is not associated with your GraphQL server's resolvers. When this event fires,
                 * your resolvers have not yet executed
                 */
                didResolveOperation(requestContext) {
                    console.log('[federated-gateway][contextPlugin][didResolveOperation] creating context...');
                    requestContext.context.headersToForward.push({ key: "x-client-name", value: "federated-gateway" });
                },
            }
        }
    };
};
