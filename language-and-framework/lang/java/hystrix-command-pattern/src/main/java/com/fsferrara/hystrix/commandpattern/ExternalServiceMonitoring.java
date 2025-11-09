package com.fsferrara.hystrix.commandpattern;

import com.fsferrara.hystrix.commandpattern.service.ExternalServiceCommand;
import com.netflix.hystrix.HystrixCommandKey;
import com.netflix.hystrix.HystrixCommandMetrics;

class ExternalServiceMonitoring {

    private final long millis;

    public ExternalServiceMonitoring(long millis) {
        this.millis = millis;
    }

    public void run() {
        Thread t = new Thread(() -> {
            while (true) {
                monitor();
                try {
                    Thread.sleep(millis);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        });
        t.setDaemon(true);
        t.start();
    }

    private void monitor() {
        HystrixCommandMetrics externalServiceCommandMetrics = HystrixCommandMetrics.getInstance(HystrixCommandKey.Factory.asKey(ExternalServiceCommand.HYSTRIX_COMMAND_GROUP_KEY));
        StringBuilder metrics = new StringBuilder();
        if (externalServiceCommandMetrics != null) {
            HystrixCommandMetrics.HealthCounts health = externalServiceCommandMetrics.getHealthCounts();
            metrics.append("Requests: ").append(health.getTotalRequests()).append(" ");
            metrics.append("Errors: ").append(health.getErrorCount()).append(" (").append(health.getErrorPercentage()).append("%)   ");
            metrics.append("Mean: ").append(externalServiceCommandMetrics.getExecutionTimePercentile(50)).append(" ");
            metrics.append("75th: ").append(externalServiceCommandMetrics.getExecutionTimePercentile(75)).append(" ");
            metrics.append("90th: ").append(externalServiceCommandMetrics.getExecutionTimePercentile(90)).append(" ");
            metrics.append("99th: ").append(externalServiceCommandMetrics.getExecutionTimePercentile(99)).append(" ");
        }
        System.out.println("externalServiceCommandMetrics: " + metrics.toString());
    }
}
