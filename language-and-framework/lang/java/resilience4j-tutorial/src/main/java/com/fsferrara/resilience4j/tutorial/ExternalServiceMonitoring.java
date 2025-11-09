package com.fsferrara.resilience4j.tutorial;

import com.fsferrara.resilience4j.tutorial.service.ExternalService;
import io.github.resilience4j.bulkhead.ThreadPoolBulkhead;

class ExternalServiceMonitoring {

    private final long millis;
    private final ExternalService externalService;
    private final ThreadPoolBulkhead threadPoolBulkhead;

    public ExternalServiceMonitoring(long millis) {
        this.millis = millis;
        this.externalService = ExternalService.getInstance();
        this.threadPoolBulkhead = externalService.getThreadPoolBulkhead();
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
        StringBuilder metrics = new StringBuilder();
        metrics.append("ExternalService Metrics: ");
        // TODO collect metrics here if possible

        int threadPoolSize = threadPoolBulkhead.getMetrics().getThreadPoolSize();

        metrics.append("threadPoolSize:").append(threadPoolSize);

        System.out.println(metrics.toString());
    }
}
