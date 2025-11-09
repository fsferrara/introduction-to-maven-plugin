const SDC = require('statsd-client');


const statsdConfig = {
    host: process.env.STATSD_HOST || 'localhost',
    port: 8125,
    prefix: "statsd-metrics-exporter"
  };
const sdc = new SDC(statsdConfig);

const timer = new Date();

let loops=0;
setInterval(() => {

    console.info("~ Sending chunk no. " + ++loops);

    /* COUNTERS
    Counters are like gauges aggregated at the server rather than the client.
    They will accumulate over a period of time, and then flushed, resetting their value to 0.

    They can be used, for example, to count how many calls is an endpoint receiving over time:

        <metric name>:<value>|c[|@<rate>]

    The rate is optional and represents how many times the metric has been sent.
    For instance, if the rate is 0.1, this means that the metric has only been sent 1/10 of the times.
    Which means that the value must be first multiplied by 10 at the server.

    If someone sends `myMetric:2|c|@0.1`, the server will understand that the current value of myMetric is 20.
    */
    // Increment counter by 10
    sdc.increment('node.counter', 10);


    /* GAUGE
    Gauges are instantaneous measurements of a value, like the speedometer in a car.
    They can increase, decrease or be set to a certain value.

    They are a good option of you need to instrument, for example, the current load of the system.

        <metric name>:<value>|g
    
    We can also add a sign to the gauge, so instead of explicitly setting the value,
    it will be increased or decreased (method sdc.gaugeDelta).

        <metric name>:+<value>|g
        <metric name>:-<value>|g
     */
    // Set gauge to 10
    sdc.gauge('node.gauge', 10);


    /* TIMERS
    Timers are a measure of milliseconds between the start and end of a given event.

    This can be used, for example, when you need to measure the request time for a service
    or how long a user has been waiting for the web page to display.

        <metric name>:<value>|ms[|@<rate]

    The rate is also optional here and it has the same meaning as in the Counter rate
    */
    // Calculates time diff of time between the variable and when the function was called
    sdc.timing('node.timer', timer);


    /* SETS
    Sets can be used to count the number of unique occurrences between flushes.
    When a metric is sent with a specific value, this is counted as an occurrence.

        <metric name>:<value>|s
    */
    // Set will count just 2 elements since '50' is repeated
    sdc.set('node.set', 50);
    sdc.set('node.set', 100);
    sdc.set('node.set', 50);


    /* HISTOGRAMS
    The histograms are also a measure of time, but they are calculated at the server side.
    As the data exported by the client is the same, this is just an alias for the Timer type.

        <metric name>:<value>|h
    */
    // Histogram with tags
    sdc.histogram('node.histogram', 10, { foo: 'bar' });

    
    /* METERS
    Meters are special case of a Counter calculated at the server.
    They measure the rate of events, for example, the number of requests per second.
    In addition to the mean rate, meters also track 1-, 5-, and 15-minute moving averages.

    Meters can be sent in full format:

        <metric name>:<value>|m

    But also in a short format which means that the counter will be increased by 1:

        <metric name>
    */
    // Does statsd-client support meters?


    // Optional - stop NOW
    // sdc.close();

}, 1000 * Math.random());
