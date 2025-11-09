const { RemoteGraphQLDataSource } = require('@apollo/gateway');

class ContextDataSource extends RemoteGraphQLDataSource {
    willSendRequest({ request, context }) {
        if (context.headersToForward) {
            // copy the headers from the context and forward them upstream
            context.headersToForward.forEach(({ key, value }) => {
                request.http.headers.set(key, value);
            });
        }
    }
}

module.exports = ContextDataSource;
