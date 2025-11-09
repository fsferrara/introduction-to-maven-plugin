# Statsd-Graphite with Generator

Uses [hopsoft/graphite-statsd](https://github.com/hopsoft/docker-graphite-statsd) to collect metrics from the `statsd-metrics-generator` sandbox project.

## Description

Configure `statsd-metrics-generator` to send the metrics to `graphite-statsd` statsd server.
To visualize the metrics, `graphite-statsd` provide a [Graphite web interface](http://localhost:81/).

### Start

```
docker-compose up -d
```

### Stop

```
docker-compose down
```
