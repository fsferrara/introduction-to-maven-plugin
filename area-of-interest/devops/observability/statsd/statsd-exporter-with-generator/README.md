# Statsd-Exporter with Generator


```
docker run --name=prom-statsd-exporter \
    -p 9102:9102 \
    -p 8125:8125/udp \
    -v $PWD/statsd-metrics-generator-mapping.yml:/tmp/statsd-metrics-generator-mapping.yml \
    prom/statsd-exporter \
        --statsd.mapping-config=/tmp/statsd-metrics-generator-mapping.yml \
        --statsd.listen-udp=:8125 \
        --web.listen-address=:9102
```

## Send fake statsd metrics to 8125/UDP

```
echo "statsd-metrics-exporter.node.timer:102522|ms" | netcat -nuc 127.0.0.1 8125
```

docker rm -f prom-statsd-exporter
