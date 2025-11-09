# Federated Gateway - Example

Hello! This is a very basic example of a federated gateway.
It's using Apollo tools and consists of two implemeting services (products and reviews) and one federated gateway that composes its graph by _introspecting_ the implementing services.

There is only one originating service with one entity (i.e. `Product`). All the code contains
comments with an explaination.

To start issue `docker-compose up` and then:
```
curl 'http://localhost:4000/' \
  -H 'Accept-Encoding: gzip, deflate, br' \
  -H 'Content-Type: application/json' \
  -H 'Accept: application/json' \
  --data-binary '{"query":"{ review {product { upc, name, price},stars,text }}"}'
```

More info is in the [official documentation](https://www.apollographql.com/docs/federation/).
